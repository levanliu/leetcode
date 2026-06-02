load("@bazel_skylib//rules:common_settings.bzl", "bool_flag")

bool_flag(
    name = "rhel_9",
    build_setting_default = True,
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
