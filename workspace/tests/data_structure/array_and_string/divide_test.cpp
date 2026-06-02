#include "workspace/src/data_structure/array_and_string/divide.cpp"
#include <catch2/catch_test_macros.hpp>
#include <climits>

TEST_CASE("divide", "[data_structure][array_and_string][divide]") {
    using namespace ns_data_structure_array_and_string_divide;
    Solution sol;
    REQUIRE(sol.divide(10, 3) == 3);
    REQUIRE(sol.divide(7, -2) == -3);
    REQUIRE(sol.divide(INT_MIN, -1) == INT_MAX);
}
