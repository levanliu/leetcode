#!/bin/bash

BAZEL_CMD="bazelisk"

# Create coverage directory
mkdir -p coverage_results

echo "🔍 Running Bazel coverage with proper instrumentation..."

# Run coverage with the recommended flags using .bazelrc config
# Exclude external_sdk_example targets — they depend on @materiallink_sdk which
# is not available in this repository (SDK customer templates only).
$BAZEL_CMD coverage --config=coverage \
    --build_tag_filters="-external_sdk_example" \
    --test_tag_filters="-external_sdk_example" \
    -- //workspace/... -//workspace/src/sdk/packaging/...

echo "🔍 Looking for coverage report..."

# Check for the standard coverage report location
COVERAGE_REPORT="bazel-out/_coverage/_coverage_report.dat"

if [ -f "$COVERAGE_REPORT" ]; then
    echo "✅ Found coverage report: $COVERAGE_REPORT"
    
    # Copy the report to our results directory
    cp "$COVERAGE_REPORT" coverage_results/coverage_report.dat || {
        echo "⚠️ Permission denied copying coverage report. Attempting to fix permissions..."
        chmod 644 coverage_results/coverage_report.dat 2>/dev/null || true
        cp "$COVERAGE_REPORT" coverage_results/coverage_report.dat
    }
    # Generate HTML coverage report if genhtml is available
    if command -v genhtml >/dev/null 2>&1; then
        echo "🎨 Generating HTML coverage report..."
        # Create output directory
        mkdir -p coverage_results/html_report
        # Strip unwanted paths (test fixtures, helpers) from the .dat before rendering
        FILTERED_REPORT="coverage_results/coverage_report_filtered.dat"
        if command -v lcov >/dev/null 2>&1; then
            lcov --gcov-tool=/opt/rh/gcc-toolset-12/root/bin/gcov \
                --remove coverage_results/coverage_report.dat \
                "*/tests/*" \
                -o "$FILTERED_REPORT" 2>/dev/null || cp coverage_results/coverage_report.dat "$FILTERED_REPORT"
        else
            cp coverage_results/coverage_report.dat "$FILTERED_REPORT"
        fi
        # Use genhtml with ignore-errors option to handle path mismatches in different environments
        # Write a temporary lcovrc to set function coverage thresholds (no CLI flags for these in this genhtml version)
        LCOVRC_TMP=$(mktemp)
        echo "genhtml_function_hi_limit = 60" >> "$LCOVRC_TMP"
        echo "genhtml_function_med_limit = 50" >> "$LCOVRC_TMP"
        if genhtml "$FILTERED_REPORT" \
            -o coverage_results/html_report \
            --config-file "$LCOVRC_TMP" \
            --title "Workspace Coverage Report" \
            --ignore-errors source 2>/dev/null; then
            echo "📊 HTML coverage report generated at: coverage_results/html_report/index.html"
        else
            echo "⚠️ HTML report generation failed, but coverage data is available"
        fi
        rm -f "$LCOVRC_TMP"
    else
        echo "ℹ️ genhtml not available."
    fi
    
    # Generate coverage summary if lcov is available
    if command -v lcov >/dev/null 2>&1; then
        echo "📈 Generating coverage summary..."
        # Use the same gcov version as specified in .bazelrc
        lcov --gcov-tool=/opt/rh/gcc-toolset-12/root/bin/gcov --summary "$COVERAGE_REPORT" > coverage_results/coverage_summary.txt 2>/dev/null || true
        echo "📊 Coverage summary saved to: coverage_results/coverage_summary.txt"
    fi
    
    echo "✅ Coverage analysis completed successfully!"
    echo "📁 Coverage data: coverage_results/coverage_report.dat"
    
    # Show basic coverage statistics
    if [ -s "$COVERAGE_REPORT" ]; then
        LINES_FOUND=$(grep -c "^LF:" "$COVERAGE_REPORT" 2>/dev/null || echo "0")
        LINES_HIT=$(grep -c "^LH:" "$COVERAGE_REPORT" 2>/dev/null || echo "0") 
        FILES_COVERED=$(grep -c "^SF:" "$COVERAGE_REPORT" 2>/dev/null || echo "0")
        echo "📈 Coverage Statistics:"
        echo "   📁 Files covered: $FILES_COVERED"
        echo "   📊 Lines found: $LINES_FOUND"
        echo "   ✅ Lines hit: $LINES_HIT"
    fi
    
else
    echo "⚠️ Coverage report not found at expected location: $COVERAGE_REPORT"
    echo "🔍 Searching for alternative coverage files..."
    
    # Search for coverage files in bazel-out directory
    find bazel-out -name "*coverage*" -type f 2>/dev/null | head -5 | while read -r file; do
        echo "   Found: $file"
    done
    
    # Also check the Bazel execution root
    if [ -d "$(bazel info execution_root 2>/dev/null)" ]; then
        EXEC_ROOT=$(bazel info execution_root)
        find "$EXEC_ROOT" -name "*coverage*.dat" 2>/dev/null | head -3 | while read -r file; do
            echo "   Found in execroot: $file"
            # Copy the first one we find as a fallback
            if [ ! -f "coverage_results/coverage_report.dat" ]; then
                cp "$file" coverage_results/coverage_report.dat
                echo "   ✅ Copied fallback coverage report"
            fi
        done
    fi
fi

echo "📊 Coverage script completed!"
