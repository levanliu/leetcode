#!/usr/bin/env bash
#
# Ship the environment to the C++ action
#
set -eu

# Set-up the environment


# Call the C++ compiler
/opt/hp93000rt/el7/x86_64/llvm-clang-21/bin/clang-scan-deps -format=p1689 -- /opt/hp93000rt/el7/x86_64/llvm-clang-21/bin/clang-21 "$@" >"$DEPS_SCANNER_OUTPUT_FILE"
