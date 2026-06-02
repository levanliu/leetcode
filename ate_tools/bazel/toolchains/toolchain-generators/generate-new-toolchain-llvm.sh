#!/bin/zsh
set -e # -o pipefail
set -u
set -x

# tools/cpp/cc_configure.bzl
# tools/cpp/unix_cc_configure.bzl

source $(dirname "$0")/common.sh

readonly WORKSPACE_ROOT="${1:-$(git rev-parse --show-toplevel)}"

readonly COMPILER=clang
# gcc supported on rhel7 is 12, however on rhel9 it is currently 14
# NOTE: all gcc_toolset_*_path variables point to devtoolset-12 on rhel7
#       see common_environment.bzl for more details
# This points to the variable we want to use from common_envirnment.bzl
readonly DEVTOOLSET_VARIABLE_VERSION=14
# Actuall gcc version used on rhel7
readonly DEVTOOLSET_VERSION_EL7=12
# Actual gcc version used on rhel9
readonly DEVTOOLSET_VERSION_EL9=14
readonly FROM_VERSION=21
readonly TO_VERSION=22
readonly FROM_NAME="llvm-clang-${FROM_VERSION}"
readonly TO_NAME="llvm-clang-${TO_VERSION}"
readonly DESTINATION="ate_tools/bazel/toolchains/${TO_NAME}"

clone_clean_bazel_examples_repo
readonly CPP_TUTORIAL="${BAZEL_EXAMPLES}/cpp-tutorial/stage3"

pushd "${CPP_TUTORIAL}"

readonly DEVTOOLSET_DIR_EL7="devtoolset-${DEVTOOLSET_VERSION_EL7}"
readonly DEVTOOLSET_DIR_EL9="gcc-toolset-${DEVTOOLSET_VERSION_EL9}"
[[ $REDHAT_MAJOR_VERSION = 7 ]] && readonly DEVTOOLSET_DIR=$DEVTOOLSET_DIR_EL7 || readonly DEVTOOLSET_DIR=$DEVTOOLSET_DIR_EL9
readonly DEVTOOLSET_ROOT=/opt/rh/${DEVTOOLSET_DIR}/root/usr

export LLVM_ROOT=/opt/hp93000rt/el${REDHAT_MAJOR_VERSION}/x86_64/${TO_NAME}
# Most of the following env vars are useless, see configure_unix_toolchain.
export AR=${LLVM_ROOT}/bin/llvm-ar
export BAZEL_LLVM_COV=${LLVM_ROOT}/bin/llvm-cov
export CC=${LLVM_ROOT}/bin/${COMPILER}
export CC_CONFIGURE_DEBUG=1
export CPP=${LLVM_ROOT}/bin/clang-cpp
export CXX=${LLVM_ROOT}/bin/clang++
export GCOV=${LLVM_ROOT}/bin/llvm-cov
export NM=${LLVM_ROOT}/bin/llvm-nm
export OBJCOPY=${LLVM_ROOT}/bin/llvm-objcopy
export OBJDUMP=${LLVM_ROOT}/bin/llvm-objdump
export PATH=${LLVM_ROOT}/bin:/bin:/usr/bin:/usr/local/bin
echo "8.2.0" > .bazelversion
bazelisk clean --expunge
# https://github.com/bazelbuild/bazel/issues/10134
bazelisk build --incompatible_use_cc_configure_from_rules_cc --disk_cache= --remote_cache= --subcommands //...

when_from_version_and_to_version_not_same "$FROM_VERSION" "$TO_VERSION" "$FROM_NAME" "$TO_NAME" "$WORKSPACE_ROOT"

pushd "${WORKSPACE_ROOT}/${DESTINATION}"
sed -i "s/${COMPILER}${FROM_VERSION}/${COMPILER}${TO_VERSION}/" *(.)
cp --archive --verbose ${CPP_TUTORIAL}/bazel-stage3/external/rules_cc++cc_configure_extension+local_config_cc/*(.) .
mv --verbose BUILD BUILD.bazel
rm --verbose REPO.bazel module.modulemap
cp --verbose ${CPP_TUTORIAL}/bazel-stage3/external/rules_cc++cc_configure_extension+local_config_cc/*(@) .
rm --verbose armeabi_cc_toolchain_config.bzl

sedscript_el7_to_el9=`mktemp`
cat >${sedscript_el7_to_el9} <<EOF
s#${DEVTOOLSET_DIR_EL7}#${DEVTOOLSET_DIR_EL9}#g
s#/el7/#/el9/#g
s#/c++/${DEVTOOLSET_VERSION_EL7}#/c++/${DEVTOOLSET_VERSION_EL9}#g
EOF

sedscript_el9_to_el7=`mktemp`
cat >${sedscript_el9_to_el7} <<EOF
s#${DEVTOOLSET_DIR_EL9}#${DEVTOOLSET_DIR_EL7}#g
s#/el9/#/el7/#g
s#/c++/${DEVTOOLSET_VERSION_EL9}#/c++/${DEVTOOLSET_VERSION_EL7}#g
EOF

sed -f $sedscript_el7_to_el9 cc_wrapper.sh > cc_wrapper_el9.sh
sed -f $sedscript_el9_to_el7 cc_wrapper.sh > cc_wrapper_el7.sh
sed -f $sedscript_el7_to_el9 deps_scanner_wrapper.sh > deps_scanner_wrapper_el9.sh
sed -f $sedscript_el9_to_el7 deps_scanner_wrapper.sh > deps_scanner_wrapper_el7.sh

sed -f $sedscript_el7_to_el9 builtin_include_directory_paths > builtin_include_directory_paths_el9
sed -f $sedscript_el9_to_el7 builtin_include_directory_paths > builtin_include_directory_paths_el7
rm --verbose ${sedscript_el9_to_el7} ${sedscript_el7_to_el9}
sed -i '\%/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk%d' builtin_include_directory_paths_el{7,9}
rm cc_wrapper.sh builtin_include_directory_paths deps_scanner_wrapper.sh
chmod --verbose 0644 BUILD.bazel cc_toolchain_config.bzl builtin_include_directory_paths_*
chmod --verbose 0755 deps_scanner_wrapper_el*.sh cc_wrapper_el*.sh
git add cc_wrapper_el*.sh deps_scanner_wrapper*.sh builtin_include_directory_paths_el*

sedscript=`mktemp`
cat >${sedscript} <<EOF
/^load(":armeabi_cc_toolchain_config.bzl", "armeabi_cc_toolchain_config")$/d

/^package(/i\\
load("//:ate_tools/env_cfg/install_dirs.bzl", "rpmRoot")\\
load("//:common_environment.bzl", "gcc_toolset_${DEVTOOLSET_VARIABLE_VERSION}_path", "gcc_toolset_${DEVTOOLSET_VARIABLE_VERSION}_gcc_ver")\\
load("@adv_rhel//:defs.bzl", "rhel_version")\\

s/cc_wrapper\.sh/cc_wrapper_el" + rhel_version() + ".sh/
s/deps_scanner_wrapper\.sh/deps_scanner_wrapper_el" + rhel_version() + ".sh/g
s/:builtin_include_directory_paths"/:builtin_include_directory_paths_el" + rhel_version()/
/:module.modulemap"/d
s/tool_paths = {"ar":/tool_paths = {\\n        "ar":/
s#"/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk"##
s#/bin/cpp#${LLVM_ROOT}/bin/clang-cpp#
s#/bin/objcopy#${LLVM_ROOT}/bin/llvm-objcopy#
s#/bin/objdump#${LLVM_ROOT}/bin/llvm-objdump#
s#/bin/strip#${LLVM_ROOT}/bin/llvm-strip#
s#"/bin/ld"#"${LLVM_ROOT}/bin/ld.lld"#
s#/bin/nm#${LLVM_ROOT}/bin/llvm-nm#
s#/bin/dwp#${LLVM_ROOT}/bin/llvm-dwp#
s/"cc-compiler-k8"/"${COMPILER}${TO_VERSION}_x86_64_toolchain"/
s/\(\sname = \)"local",/\1"${COMPILER}${TO_VERSION}_toolchain_config",/
/"-Wno-free-nonheap-object",/d
s/toolchain_config = ":local",/toolchain_config = ":${COMPILER}${TO_VERSION}_toolchain_config",/
/# This is the entry point for --crosstool_top.  Toolchains are found/,/^$/ d
/"-B\\/opt\\/rh\\/${TO_NAME}\\/root\\/usr\\/bin",/d
/"-pass-exit-codes"],/d
/compile_flags = \\["-fstack-protector",/ a\\
    "-fdiagnostics-color",\\
    "-fstack-protector-strong",
s/\\(compile_flags = \\[\\)"-fstack-protector",/\\1/
s/"-std=c++14"//
/supports_start_end_lib = True,/,$ {
  /supports_start_end_lib/n
  /)/d
  /^$/d
  /# Android tooling requires a default toolchain for the armeabi-v7a cpu./,$ d
}
/armeabi_cc_toolchain_config(name = "stub_armeabi-v7a")/d
EOF
sed -i -f ${sedscript} BUILD.bazel
rm --verbose ${sedscript}

sedscript=`mktemp`
cat >${sedscript} <<EOF
/"ACTION_NAMES")/ a\\
load("//:ate_tools/env_cfg/install_dirs.bzl", "rpmRoot")
/def layering_check_features(compiler, .*):/ i\\
def check_concurrency_features(compiler):\\
    if compiler != "clang":\\
        return []\\
    return [\\
        feature(\\
            name = "check_concurrency_features",\\
            enabled = True,\\
            flag_sets = [\\
                flag_set(\\
                    actions = [\\
                        ACTION_NAMES.cpp_compile,\\
                    ],\\
                    flag_groups = [\\
                        flag_group(\\
                            flags = [\\
                                "-Xclang",\\
                                "-load",\\
                                "-Xclang",\\
                                rpmRoot + "${TO_NAME}-plugin/plugins/concurrency-feature-check${TO_VERSION}.so",\\
                                "-Xclang",\\
                                "-add-plugin",\\
                                "-Xclang",\\
                                "concurrency-feature-check",\\
                            ],\\
                        ),\\
                    ],\\
                ),\\
            ],\\
        ),\\
    ]\\

/fdo_prefetch_hints_feature = feature(/ i\\
    link_libcpp_feature = feature(\\
        name = "link_libcpp",\\
        flag_sets = [\\
            flag_set(\\
                actions = [\\
                    ACTION_NAMES.c_compile,\\
                    ACTION_NAMES.cpp_compile,\\
                ] + all_link_actions,\\
                flag_groups = [\\
                    flag_group(\\
                        flags = ["-stdlib=libc++"],\\
                    )\\
                ]\\
            ),\\
            flag_set(\\
                actions = all_link_actions,\\
                flag_groups = [\\
                    flag_group(\\
                        flags = [\\
                            # match LLVM commit 311f7839602344ca347816146edb68c0ffaaa060\\
                            "-L " + rpmRoot + "${TO_NAME}/lib64/x86_64-unknown-linux-gnu",\\
                            "-Wl,-rpath=" + rpmRoot + "${TO_NAME}/lib64/x86_64-unknown-linux-gnu"\\
                        ],\\
                    )\\
                ]\\
            ),\\
        ],\\
    )\\

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

/unfiltered_compile_flags_feature,/ a\\
            cxx_standard_17_feature,\\
            cxx_standard_20_feature,\\
            cxx_standard_23_feature,\\
            # Order matters: We want our users to use features = ["-treat_warnings_as_errors"]\\
            # instead of adding '-Wno-error' to copts.
/user_link_flags_feature,/ i\\
            # Order matters: We want our users to use features = ["-link_libcpp"].\\
            link_libcpp_feature,
s/] + layering_check_features(ctx.attr.compiler, .*)/& + check_concurrency_features(ctx.attr.compiler)/
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
    # exec_compatible_with = ['//:${COMPILER}'],\\
    target_compatible_with = ['@platforms//cpu:x86_64'],\\
    target_settings = ["//:is_${COMPILER}"],\\
)
s#/opt/rh/${DEVTOOLSET_DIR}/root/usr/include/c++/[0-9]\+#/opt/rh/${DEVTOOLSET_DIR}/root/usr/include/c++/" \\+ gcc_toolset_${DEVTOOLSET_VARIABLE_VERSION}_gcc_ver \\+ "#g
s#"/opt/rh/${DEVTOOLSET_DIR}#gcc_toolset_${DEVTOOLSET_VARIABLE_VERSION}_path \\+ "#g
s#/opt/rh/${DEVTOOLSET_DIR}#" \\+ gcc_toolset_${DEVTOOLSET_VARIABLE_VERSION}_path \\+ "#g
s#"/opt/hp93000rt/el[79]/x86_64#rpmRoot \\+ "#g
s#/opt/hp93000rt/el[79]/x86_64#" \\+ rpmRoot \\+ "#g

EOF
sed -i -f ${sedscript} BUILD.bazel
# rm --verbose ${sedscript}
rm --force --recursive /tmp/bazel-examples

git add "${WORKSPACE_ROOT}/${DESTINATION}"
post_process_instruction $DESTINATION
