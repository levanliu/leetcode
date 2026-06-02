#include "workspace/src/data_structure/array_and_string/amount.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("amount", "[data_structure][array_and_string][amount]") {
    using namespace ns_data_structure_array_and_string_amount;
    REQUIRE(Solution::solve(10) == 4);
    REQUIRE(Solution::solve(1) == 0);
    REQUIRE(Solution::solve(6) == 2);
}
