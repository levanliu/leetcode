#!/bin/zsh 
set -e #o pipefail # pipefail is unsupported on the current default /bin/zsh v5.0.2 installed on RHEL7
set -u
set -x

# tools/cpp/cc_configure.bzl
# tools/cpp/unix_cc_configure.bzl

source $(dirname "$0")/common.sh

readonly WORKSPACE_ROOT="${1:-$(git rev-parse --show-toplevel)}"

readonly COMPILER=gcc
readonly FROM_VERSION=14
readonly TO_VERSION=14
readonly RHEL7_TO_VERSION=12
readonly FROM_NAME="gcc-toolset-${FROM_VERSION}"
readonly TO_NAME="gcc-toolset-${TO_VERSION}"
readonly DESTINATION="bzl_tools/bazel/toolchains/${TO_NAME}"

clone_clean_bazel_examples_repo
readonly CPP_TUTORIAL="${BAZEL_EXAMPLES}/cpp-tutorial/stage3"

pushd "${CPP_TUTORIAL}"

readonly DEVTOOLSET_DIR_EL7="devtoolset-${RHEL7_TO_VERSION}"
readonly DEVTOOLSET_DIR_EL9="${TO_NAME}"
[[ $REDHAT_MAJOR_VERSION = 7 ]] && readonly DEVTOOLSET_DIR=$DEVTOOLSET_DIR_EL7 || readonly DEVTOOLSET_DIR=$DEVTOOLSET_DIR_EL9
readonly DEVTOOLSET_ROOT=/opt/rh/${DEVTOOLSET_DIR}/root/usr

# Most of the following env vars are useless, see configure_unix_toolchain.
export AR=${DEVTOOLSET_ROOT}/bin/ar
export BAZEL_LLVM_COV=${DEVTOOLSET_ROOT}/bin/cov
export CC=${DEVTOOLSET_ROOT}/bin/${COMPILER}
export CC_CONFIGURE_DEBUG=1
export CPP=${DEVTOOLSET_ROOT}/bin/cpp
export CXX=${DEVTOOLSET_ROOT}/bin/g++
export GCOV=${DEVTOOLSET_ROOT}/bin/gcov
export NM=${DEVTOOLSET_ROOT}/bin/nm
export OBJCOPY=${DEVTOOLSET_ROOT}/bin/objcopy
export OBJDUMP=${DEVTOOLSET_ROOT}/bin/objdump
export PATH=${DEVTOOLSET_ROOT}/bin:/bin:/usr/bin:/usr/local/bin
echo "8.2.0" > .bazelversion
bazelisk clean --expunge
# https://github.com/bazelbuild/bazel/issues/10134
bazelisk build --incompatible_use_cc_configure_from_rules_cc --disk_cache= --remote_cache= --subcommands //...

when_from_version_and_to_version_not_same "$FROM_VERSION" "$TO_VERSION" "$FROM_NAME" "$TO_NAME" "$WORKSPACE_ROOT"

pushd "${WORKSPACE_ROOT}/${DESTINATION}"
sed -i "s/${COMPILER}${FROM_VERSION}/${COMPILER}${TO_VERSION}/" *(.)
cp --archive --verbose ${CPP_TUTORIAL}/bazel-stage3/external/rules_cc++cc_configure_extension+local_config_cc/*(.) .
cp --archive --dereference --verbose ${CPP_TUTORIAL}/bazel-stage3/external/rules_cc++cc_configure_extension+local_config_cc/*(@) .
mv --verbose BUILD BUILD.bazel
rm --verbose REPO.bazel
cp --verbose ${CPP_TUTORIAL}/bazel-stage3/external/rules_cc++cc_configure_extension+local_config_cc/*(@) .
rm --verbose armeabi_cc_toolchain_config.bzl

sed "s#${DEVTOOLSET_DIR_EL7}#${DEVTOOLSET_DIR_EL9}#" cc_wrapper.sh > cc_wrapper_el9.sh
sed "s#${DEVTOOLSET_DIR_EL9}#${DEVTOOLSET_DIR_EL7}#" cc_wrapper.sh > cc_wrapper_el7.sh

sed -e"s#${DEVTOOLSET_DIR_EL7}#${DEVTOOLSET_DIR_EL9}#" -e"s#/${RHEL7_TO_VERSION}#/${TO_VERSION}#" builtin_include_directory_paths > builtin_include_directory_paths_el9
sed -e"s#${DEVTOOLSET_DIR_EL9}#${DEVTOOLSET_DIR_EL7}#" -e"s#/${TO_VERSION}#/${RHEL7_TO_VERSION}#" builtin_include_directory_paths > builtin_include_directory_paths_el7
rm cc_wrapper.sh builtin_include_directory_paths
sed -i '\%/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk%d' builtin_include_directory_paths_el{7,9}

chmod --verbose 0644 BUILD.bazel cc_toolchain_config.bzl builtin_include_directory_paths*
chmod --verbose 0755 cc_wrapper_el*.sh
git add cc_wrapper_el*.sh builtin_include_directory_paths_el*

sedscript=`mktemp`
cat >${sedscript} <<EOF
/^load(":armeabi_cc_toolchain_config.bzl", "armeabi_cc_toolchain_config")$/d

/^package(/i\\
load("//:common_environment.bzl", "gcc_toolset_${TO_VERSION}_gcc_ver", "gcc_toolset_${TO_VERSION}_path")\\
load("@rhel9//:defs.bzl", "rhel_version")\\

s/cc_wrapper\.sh/cc_wrapper_el" + rhel_version() + ".sh/
s/:builtin_include_directory_paths"/:builtin_include_directory_paths_el" + rhel_version()/
s/tool_paths = {"ar":/tool_paths = {\\n        "ar":/
s#"/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk"##
s#"${DEVTOOLSET_ROOT}/bin/ld#&.gold#
s/"cc-compiler-k8"/"${COMPILER}${TO_VERSION}_x86_64_toolchain"/
s/\(\sname = \)"local",/\1"${COMPILER}${TO_VERSION}_toolchain_config",/
/"-Wno-free-nonheap-object",/d
s/toolchain_config = ":local",/toolchain_config = ":${COMPILER}${TO_VERSION}_toolchain_config",/
/# This is the entry point for --crosstool_top.  Toolchains are found/,/^$/ d
/"-B\\/opt\\/rh\\/${DEVTOOLSET_DIR}\\/root\\/usr\\/bin",/d
/"-pass-exit-codes"],/d
/compile_flags = \\["-fstack-protector",/ a\\
    "-fdiagnostics-color",\\
    "-fstack-protector-strong",
s/\\(compile_flags = \\[\\)"-fstack-protector",/\\1/
s/"-O2"/"-O3"/
s/"-std=c++14"//
/supports_start_end_lib = True,/,$ {
  /supports_start_end_lib/n
  /)/d
  /^$/d
  /# Android tooling requires a default toolchain for the armeabi-v7a cpu./,$ d
}
/armeabi_cc_toolchain_config(name = "stub_armeabi-v7a")/d
s/"-g"/'-U_FORTIFY_SOURCE', '-g', '-O0', '-ggnu-pubnames'/
/"-Wl,-z,relro,-z,now",/ a\\
    "-B/opt/rh/${DEVTOOLSET_DIR}/root/usr/bin",\\
    "-Wl,--gdb-index",\\
    "-pass-exit-codes"\\
\\
    # --detect-odr-violations causes link times of sometimes > 200 secs.\\
    # SWTOOL-592\\
    #"-Wl,--detect-odr-violations",\\
\\
    # TODO: Disabled: SWTOOL-538\\
    # "-Wl,--fatal-warnings",\\
    # +++ start: protobuf\\
    # "protobuf" does not link with the original settings:\\
    #\\
    # > [...] error: undefined reference to 'std::__throw_out_of_range_fmt(char const*, ...)'\\
    #\\
    # This seems to be a link order issue.\\
    # Fix according to https://github.com/bazelbuild/bazel/issues/9254#issuecomment-562748903:\\
    #\\
    #"-lstdc++",\\
    #"-lm"\\
    ],
/opt_link_flags = \\["-Wl,--gc-sections"\\],/ a\\
        "-Wl,--gc-sections",\\
        # --detect-odr-violations causes link times of sometimes > 200 secs.\\
        # SWTOOL-592\\
        #"-Wl,--detect-odr-violations",\\
        # TODO: Disabled: SWTOOL-538\\
        # "-Wl,--fatal-warnings",\\
    ],
s/\\(opt_link_flags = \\[\\)"-Wl,--gc-sections"\\],/\1/
s#/${TO_VERSION}#/" + gcc_toolset_${TO_VERSION}_gcc_ver + "#
s#/${RHEL7_TO_VERSION}#/" + gcc_toolset_${TO_VERSION}_gcc_ver + "#
EOF
sed -i -f ${sedscript} BUILD.bazel
rm --verbose ${sedscript}

sedscript=`mktemp`
cat >${sedscript} <<EOF
/strip_debug_symbols_feature = feature(/ i\\
    cxx_standard_17_feature = feature(\\
        name = "cxx_standard_17",\\
        enabled = True,\\
        flag_sets = [\\
            flag_set(\\
                actions = all_cpp_compile_actions,\\
                flag_groups = [\\
                    flag_group(\\
                        flags = ["-std=c++17"],\\
                    ),\\
                ],\\
            ),\\
        ],\\
    )\\
\\
    cxx_standard_20_feature = feature(\\
        name = "cxx_standard_20",\\
        flag_sets = [\\
            flag_set(\\
                actions = all_cpp_compile_actions,\\
                flag_groups = [\\
                    flag_group(\\
                        flags = ["-std=c++20"],\\
                    ),\\
                ],\\
            ),\\
        ],\\
    )\\
\\
    cxx_standard_23_feature = feature(\\
        name = "cxx_standard_23",\\
        flag_sets = [\\
            flag_set(\\
                actions = all_cpp_compile_actions,\\
                flag_groups = [\\
                    flag_group(\\
                        flags = ["-std=c++23"],\\
                    ),\\
                ],\\
            ),\\
        ],\\
    )\\

/archive_param_file_feature = feature(/ i\\
    override_the_users_wishes_feature = feature(\\
        name = "override_the_users_wishes",\\
        enabled = True,\\
        # DO NOT add to this. We'll likely stop you during review anyway.\\
        flag_sets = [\\
            flag_set(\\
                actions = all_cpp_compile_actions,\\
                flag_groups = [\\
                    flag_group(\\
                        # RDHD-49481: -Woverloaded-virtual fires randomly from GCC 13 and GCC 14.\\
                        #   Do not treat it as an error to ensure builds don't break because of this.\\
                        flags = ["-Wno-error=overloaded-virtual"],\\
                    ),\\
                ],\\
            ),\\
        ],\\
    )\\

/name = "treat_warnings_as_errors",/ a\\
        enabled = True,
/unfiltered_compile_flags_feature,/ a\\
            cxx_standard_17_feature,\\
            cxx_standard_20_feature,\\
            cxx_standard_23_feature,\\
            # Order matters: We want our users to use features = ["-treat_warnings_as_errors"]\\
            # instead of adding '-Wno-error' to copts.
/treat_warnings_as_errors_feature,/ a\\
            # ... but we need to have the last word in rare occasions: whatever is in\\
            # the flag_sets of 'override_the_users_wishes' will win.\\
            override_the_users_wishes_feature,
/_sanitizer_feature(/ {N
    /        name = .*,/ {N
        /        specific_compile_flags = \[/a\\
            "-Wno-error=maybe-uninitialized",\\
            "-Wno-error=restrict",\\
            "-Wno-error=return-type",\\
            "-Wno-error=strict-overflow",\\
            "-Wno-error=uninitialized",\\
            "-Wno-error=overloaded-virtual",
    }
}
EOF
sed -i -f ${sedscript} cc_toolchain_config.bzl
rm --verbose ${sedscript}
sedscript=`mktemp`
cat >${sedscript} <<EOF
\$a\\
)\\
\\
toolchain(\\
    name = "${COMPILER}${TO_VERSION}_toolchain",\\
    toolchain = "${COMPILER}${TO_VERSION}_x86_64_toolchain",\\
    toolchain_type = "@rules_cc//cc:toolchain_type",\\
    # exec_compatible_with = ['//:toolset-${COMPILER}'],\\
    target_compatible_with = ['@platforms//cpu:x86_64'],\\
    target_settings = ["//:is_${COMPILER}"],\\
)\\
\\
toolchain(\\
    name = "default_toolchain",\\
    toolchain = "${COMPILER}${TO_VERSION}_x86_64_toolchain",\\
    toolchain_type = "@rules_cc//cc:toolchain_type",\\
    # exec_compatible_with = ['//:toolset-${COMPILER}'],\\
    target_compatible_with = ['@platforms//cpu:x86_64'],\\
    # No target_settings present\\
)
\\#/bin/llvm-profdata#d
s#"/opt/rh/${DEVTOOLSET_DIR}#gcc_toolset_${TO_VERSION}_path \\+ "#g
s#/opt/rh/${DEVTOOLSET_DIR}#" \\+ gcc_toolset_${TO_VERSION}_path \\+ "#g
EOF
sed -i -f ${sedscript} BUILD.bazel

rm --verbose ${sedscript}
rm --force --recursive /tmp/bazel-examples

git add "${WORKSPACE_ROOT}/${DESTINATION}"
post_process_instruction $DESTINATION
