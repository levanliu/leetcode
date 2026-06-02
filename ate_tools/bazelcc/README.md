# bazelcc

The purpose of the `bazelcc` tool is to create
a so-called compilation database or compile commands file
by processing the output of `bazel aquery`, i.e., in a pipeline akin to

```shell
bazel aquery --output=proto //... | bazelcc > compile_commands.json
```

(see [`bazel-compile-commands`](../bazel/bin/bazel-compile-commands)).
The `compile_commands.json` file is needed for many Clang-based tools to work correctly.


## Vendored Protocol Buffer definitions

The files [`proto/analysis_v2.proto`] and [`proto/build.proto`]
are copies of [`src/main/protobuf/analysis_v2.proto`] and [`src/main/protobuf/build.proto`]
from the Bazel project.
Only the `import build.proto` statement in `analysis_v2.proto` was adapted
to match the different project structure.
These files provide the necessary definitions to parse the output of the `bazel aquery` call.


[`proto/analysis_v2.proto`]: proto/analysis_v2.proto
[`proto/build.proto`]: proto/build.proto
[`src/main/protobuf/analysis_v2.proto`]: https://github.com/bazelbuild/bazel/blob/master/src/main/protobuf/analysis_v2.proto
[`src/main/protobuf/build.proto`]: https://github.com/bazelbuild/bazel/blob/master/src/main/protobuf/build.proto


## Tests

Run

```shell
bazelisk test //ate_tools/bazelcc:bazelcc_test --test_arg=--colour-mode=ansi
```

to execute the regression tests.
