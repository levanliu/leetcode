#!/bin/bash 
set -e #o pipefail
set -u
set -x

# This script has to be called from a "default" environment.
env | grep '^WORKSPACE\|^ENV_SCM_WORKSPACE_ROOT' && (echo "This script only works in a default environment, not after 'sw' was used." ; exit 1)

readonly REDHAT_MAJOR_VERSION=$(awk -F'=' '/VERSION_ID/ { gsub(/"/, "", $2); split($2, a, "."); print a[1] }' /etc/os-release)
readonly BAZEL_EXAMPLES="/tmp/bazel-examples"

post_process_instruction() {
    local destination=$1
    echo "\n\n\e[0;31m No other manual post-processing should be required.\n\n"\
         "git log --find-copies-harder -- ${destination} is recommended.\e[1;00m\n"
}

clone_clean_bazel_examples_repo() {
    # Support interactive debugging: The repo clone is not removed if the script aborts due to errors.
    if [ -d ${BAZEL_EXAMPLES} ] ; then
        rm --force --recursive ${BAZEL_EXAMPLES}
    fi
    pushd /tmp
        git clone --single-branch --branch main https://github.com/bazelbuild/examples bazel-examples
        # We cannot reliably do the revert - there might be newer
        # changes that cause the revert to have conflicts. To not
        # break the test, pin the main branch to a known working
        # commit.
        git -C bazel-examples reset --hard 1935ada67a44fe59c66adaccfa30ffd89fa78da8
    popd
}

when_from_version_and_to_version_not_same() {
    # from and to may be equal if we intend to re-generate the toolchain with a newer version of Bazel
    # in that case the copy from the existing toolchain would fail
    local from_version=$1
    local to_version=$2
    local from_name=$3
    local to_name=$4
    local workspace_root=$5
    local destination="bzl_tools/bazel/toolchains/${to_name}"


    if [ "${from_version}" -ne "${to_version}" ] ; then

        # Support interactive debugging: The destination repository may be in an inconsistent state of the script aborted.
        if [ -d "${workspace_root}/bzl_tools/bazel/toolchains/${to_name}" ] ; then
            KNOWN_TO_GIT=`git -C ${workspace_root} ls-files ${destination}/ | wc -l`
            if [ ${KNOWN_TO_GIT} -gt 0 ] ; then
                git -C "${workspace_root}" rm --force -r "bzl_tools/bazel/toolchains/${to_name}"
            fi
            rm --force --recursive --verbose "${workspace_root}/bzl_tools/bazel/toolchains/${to_name}"
        fi

        cp --archive --verbose "${workspace_root}/bzl_tools/bazel/toolchains/${from_name}" "${workspace_root}/$destination"
        rm --verbose ${workspace_root}/${destination}/cc_wrapper*
    fi
}
