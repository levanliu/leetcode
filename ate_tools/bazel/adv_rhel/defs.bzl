def _impl(repository_ctx):
    rhel7_result = repository_ctx.execute(
        [
            "/usr/bin/grep",
            "--quiet",
            '^VERSION_ID="7',
            "/etc/os-release",
        ],
    )

    rhel9_result = repository_ctx.execute(
        [
            "/usr/bin/grep",
            "--quiet",
            '^VERSION_ID="9',
            "/etc/os-release",
        ],
    )

    postgresql13addon_result = repository_ctx.execute(
        [
            "/usr/bin/test",
            "-f",
            "/usr/pgsql-13/include/pgtypes.h",
            # Testing the existence of "usr/pgsql-13/" is insufficient because
            # the removal of the PostgreSQL 13 RPMs leaves a thin directory tree.
        ],
    )

    repository_ctx.template("BUILD.bazel", repository_ctx.workspace_root.get_child("ate_tools", "bazel", "adv_rhel", "BUILD.bazel.tpl"), substitutions = {
        # logic is inverse: grep returns 0 for success (match)
        "PLACEHOLDER_IS_RHEL7": "True" if not rhel7_result.return_code else "False",
        "PLACEHOLDER_IS_RHEL9": "True" if not rhel9_result.return_code else "False",
    }, executable = False)

    repository_ctx.template("defs.bzl", repository_ctx.workspace_root.get_child("ate_tools", "bazel", "adv_rhel", "defs.bzl.tpl"), substitutions = {
        "PLACEHOLDER_IS_RHEL7": "True" if not rhel7_result.return_code else "False",
        "PLACEHOLDER_IS_RHEL9": "True" if not rhel9_result.return_code else "False",
        "PLACEHOLDER_HAS_POSTGRESQL13ADDON": "True" if not postgresql13addon_result.return_code else "False",
    }, executable = False)

adv_rhel_repository = repository_rule(
    implementation = _impl,
    configure = True,
    local = True,
)

def load_adv_rhel():
    adv_rhel_repository(
        name = "adv_rhel",
    )

# Used by MODULE.bazel
adv_rhel_extension = module_extension(
    implementation = lambda ctx: load_adv_rhel(),
)
