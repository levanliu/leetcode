#include "workspace/src/data_structure/array_and_string/swap.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("swapInts", "[data_structure][array_and_string][swap]") {
    using namespace ns_data_structure_array_and_string_swap;
    SECTION("basic swap") {
        int a = 1, b = 2;
        Solution::swapInts(a, b);
        REQUIRE(a == 2);
        REQUIRE(b == 1);
    }
    SECTION("same value") {
        int a = 5, b = 5;
        Solution::swapInts(a, b);
        REQUIRE(a == 5);
        REQUIRE(b == 5);
    }
}
