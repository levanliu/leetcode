# C++ toolchain generator scripts for Bazel

We cannot rely on the auto-generated toolchains and thus disable them via `.bazelrc`:

```
common --repo_env=BAZEL_DO_NOT_DETECT_CPP_TOOLCHAIN=1
```

## Reasons

* The `tool_paths` dictionary has to be changed so that all tools get
  taken from e.g. the gcc-toolset or the LLVM/Clang toolset.
* The devtoolset and LLVM/Clang toolchains have additional features that are not (yet) available in the default ones:
  - adding features to pick the ISO C++ standard
  - libc++ instead of libstdc++
  - support for the clang-concurrency-feature plugin
  - ...
* We need to relax the warnings-as-errors policy for the time being.
* We can hard-code the compiler flags for embedded cross compilers directly in the toolchains.
* ...

Historically, there have been a couple more reasons to not rely on
toolchain auto-configuration:

* support for sanitizers had not been auto-generated prior to v6.1.0
* the `XOC_FILE_ID` feature is implemented in the devtoolset and LLVM/Clang toolchains
* ...

## Mode of operation

Copying existing toolchain files and just bump their versions is a bad
idea because newer versions of Bazel commonly add new features. We do
not want to miss out on those.

The collection of scripts in this directory follows a common pattern:

* use `cpp-tutorial/stage3` from the latest state of the
  [bazel-examples](https://github.com/bazelbuild/examples) repository
* set a couple of environment variables (`CC`, ...) to point toolchain
  auto-detection into the right direction
* call `bazelisk build //...` so that toolchains get auto-generated
* create and use a couple of `sed` scripts to manipulate the auto-
  generated toolchain files to fit our needs

## Running

```sh
zsh ./generate-new-toolchain-llvm.sh /workspaces/socbm784/olibruns/ws-dev-olibruns-sb59
```

The resulting toolchain files require post-processing. At the very least
you should compare the (possibly staged) changes with commands like

```sh
git diff --find-copies-harder [--staged] ate_tools/bazel/toolchains
```

## Testing
The scripts are run as a part of ZSG_TEST. However make sure that the toolchains to be tested start with `generate-*`
* The test implementation can be found in `$WORKSPACE/local-CMF-tools/test/do_zsg_tests.d/020_bazel-verify-toolchain-changes`

## TODO

* The toolchains are currently targeted at the code below `$WORKSPACE`.
  We may need to relax a couple of assumptions and/or move them into the
  `zenith_library()` definition.
* One could argue that there is a lot of duplication going on between
  theses scripts. So far, it turned out to be better to focus on the
  problems of just one toolchain at a time. Merging the functionality
  into one script has never been done.
* The `FROM_VERSION` and `TO_VERSION` variables have to be set by hand.
* There may be a problem in the logic when a new toolchain version is
  introduced. The script may terminate with "No such file or directory."
