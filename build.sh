#!/bin/bash
set -euo pipefail

# Default values
COMPILATION_MODE="opt"

# Function to display usage
usage() {
    cat << EOF
Usage: $0 [OPTIONS]
Options:
  --debug     Build with debug configuration
  --release   Build with release configuration (default)
  --clean     Clean the Bazel build (expunge)
  --help      Show this help message and exit
EOF
    exit 0
}

# Parse command line arguments
case "${1:-}" in
    --help)
        usage
        ;;
    --clean)
        bazelisk clean --expunge
        exit 0
        ;;
    --debug)
        COMPILATION_MODE="dbg"
        ;;
    --release)
        COMPILATION_MODE="opt"
        ;;
    "")
        # Default to release mode
        ;;
    *)
        echo "Error: Unknown option: $1" >&2
        usage
        ;;
esac

echo "Create compilation database ..."
bazelisk build --compilation_mode="$COMPILATION_MODE" //ate_tools/bazelcc:bazelcc

OUT_BASE="$(bazelisk info output_base)"
EXEC_ROOT="$(bazelisk info execution_root)"
SRC_ROOT="$(bazelisk info workspace)"

bazelisk aquery --compilation_mode="$COMPILATION_MODE" --output=proto \
  "mnemonic(CppCompile, deps(//workspace/...))" \
  | bazel-bin/ate_tools/bazelcc/bazelcc "$OUT_BASE" "$EXEC_ROOT" "$SRC_ROOT" \
  > compile_commands.json

# Build all targets
echo "Building with compilation mode: $COMPILATION_MODE"
if ! bazelisk build --compilation_mode="$COMPILATION_MODE" //workspace/...; then
    echo "Error: Bazel build failed" >&2
    exit 1
fi

# Run tests
echo "Running tests ..."
if ! bazelisk test --compilation_mode="$COMPILATION_MODE" //workspace/tests/...; then
    echo "Error: Tests failed" >&2
    exit 1
fi

echo "Build and tests passed."

echo "Build completed successfully!"