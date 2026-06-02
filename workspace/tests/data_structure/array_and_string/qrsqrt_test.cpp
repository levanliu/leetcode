#include "workspace/src/data_structure/array_and_string/qrsqrt.cpp"
#include <catch2/catch_test_macros.hpp>
#include <cmath>

TEST_CASE("fastInverseSqrt", "[data_structure][array_and_string][qrsqrt]") {
    using namespace ns_data_structure_array_and_string_qrsqrt;
    SECTION("sqrt(4) approx 0.5") {
        float r = Solution::fastInverseSqrt(4.0f);
        REQUIRE(std::fabs(r - 0.5f) < 0.01f);
    }
    SECTION("sqrt(1) approx 1.0") {
        float r = Solution::fastInverseSqrt(1.0f);
        REQUIRE(std::fabs(r - 1.0f) < 0.01f);
    }
}
