load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")

bool_flag(
    name = "rhel_7",
    build_setting_default = PLACEHOLDER_IS_RHEL7,
)

config_setting(
    name = "7",
    flag_values = {
        "rhel_7": "True",
    },
)

bool_flag(
    name = "rhel_9",
    build_setting_default = PLACEHOLDER_IS_RHEL9,
)

config_setting(
    name = "9",
    flag_values = {
        "rhel_9": "True",
    },
)

exports_files([
    "defs.bzl",
])
