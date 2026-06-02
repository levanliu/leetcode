#!/bin/bash

echo "🧪 Starting automated tests with Catch2..."

BAZEL_CMD="bazelisk"

# Create directories for test results
mkdir -p test_results

echo "🔍 Looking for test targets..."
TEST_TARGETS=$($BAZEL_CMD query "tests(//workspace/tests/...)" 2>/dev/null || echo "")

if [ -n "$TEST_TARGETS" ]; then
    echo "✅ Found test targets:"
    echo "$TEST_TARGETS"
    echo "▶️ Running tests with Catch2 JUnit XML output..."
    
    set +e  # Don't exit on command failure
    $BAZEL_CMD test //workspace/tests/... \
        --test_output=all \
        --cache_test_results=no \
        --compilation_mode=opt \
        --test_tag_filters=-external,-third_party
    set -e  # Re-enable exit on failure
    
    # Copy test results (both test.log and test.xml files)
    echo "📋 Collecting test results from workspace tests..."
    
    # Clear test_results directory first
    rm -f test_results/* 2>/dev/null || true
    
    if [ -d "bazel-testlogs/workspace/tests" ]; then
        echo "📝 Found workspace test logs, copying files..."

        # Copy test.xml files with renamed format
        find bazel-testlogs/workspace/tests -name "test.xml" -type f | while read -r xml_file; do
            # Extract test name from path
            TEST_NAME=$(echo "$xml_file" | sed 's|.*/workspace/tests/||' | sed 's|/test\.xml||' | sed 's|/|_|g')
            if [ -n "$TEST_NAME" ]; then
                cp "$xml_file" "test_results/${TEST_NAME}_test.xml"
            fi
        done
        
        # Copy test.log files with renamed format  
        find bazel-testlogs/workspace/tests -name "test.log" -type f | while read -r log_file; do
            # Extract test name from path
            TEST_NAME=$(echo "$log_file" | sed 's|.*/workspace/tests/||' | sed 's|/test\.log||' | sed 's|/|_|g')
            if [ -n "$TEST_NAME" ]; then
                cp "$log_file" "test_results/${TEST_NAME}_test.log"
            fi
        done

        echo "✅ Test results collected"

    else
        echo "❌ No workspace test logs found in bazel-testlogs/workspace/tests"
    fi
    
else
    echo "ℹ️ No test targets found in //workspace/..."
    echo "📝 Make sure tests are properly configured in //workspace/tests/..."
fi

echo "🧪 Test execution completed!"
