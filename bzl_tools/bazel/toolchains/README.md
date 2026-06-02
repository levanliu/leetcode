# Bazel Toolchain for SmartBuild

## Purpose

We use [Bazel Toolchains](https://docs.bazel.build/versions/master/toolchains.html)
for multiple purposes:
* to select the C++ compiler (alternative: always set $PATH)
* to add the compile option '-DXOC_FILE_ID="<source file name>"'
  (alternative: create and use a compiler wrapper script)

## Implementation

The implementation is based on https://stackoverflow.com/a/64224213.

Afterwards, you might want to modify attribute `name` in rule `cc_toolchain_suite`.
Make sure that the value of _crosstool_top_ in file `.bazelrc` matches this name.

Furthermore, according to https://github.com/bazelbuild/bazel/issues/9254#issuecomment-562748903,
you have to remove "-lstdc++" (and "-lm") from link_opts and add it to "link_libs".