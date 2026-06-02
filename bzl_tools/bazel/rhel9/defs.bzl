def _impl(repository_ctx):
    repository_ctx.template("BUILD.bazel", repository_ctx.workspace_root.get_child("bzl_tools", "bazel", "rhel9", "BUILD.bazel.tpl"), substitutions = {}, executable = False)

    repository_ctx.template("defs.bzl", repository_ctx.workspace_root.get_child("bzl_tools", "bazel", "rhel9", "defs.bzl.tpl"), substitutions = {}, executable = False)

rhel9_repository = repository_rule(
    implementation = _impl,
    configure = True,
    local = True,
)

def load_rhel9():
    rhel9_repository(
        name = "rhel9",
    )

# Used by MODULE.bazel
rhel9_extension = module_extension(
    implementation = lambda ctx: load_rhel9(),
)
