#!/bin/bash
#
# Ship the environment to the C++ action
#
set -eu

# Set-up the environment


# Call the C++ compiler

/opt/rh/gcc-toolset-14/root/usr/bin/gcc -E -x c++ -fmodules-ts -fdeps-file=out.tmp -fdeps-format=p1689r5 "$@" >"$DEPS_SCANNER_OUTPUT_FILE"
