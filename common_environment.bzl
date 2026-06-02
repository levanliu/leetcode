# Common path variables

load("@adv_rhel//:defs.bzl", "is_rhel7")

# GCC 13 is only available on RHEL9. So we need to still call devtoolset-12 on RHEL7.
gcc_toolset_13_path = "/opt/rh/devtoolset-12" if is_rhel7() else "/opt/rh/gcc-toolset-13"
gcc_toolset_13_gcc_ver = "12" if is_rhel7() else "13"
# GCC 14 is only available on RHEL9. So we need to still call devtoolset-12 on RHEL7.
gcc_toolset_14_path = "/opt/rh/devtoolset-12" if is_rhel7() else "/opt/rh/gcc-toolset-14"
gcc_toolset_14_gcc_ver = "12" if is_rhel7() else "14"
