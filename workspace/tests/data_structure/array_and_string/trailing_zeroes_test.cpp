#include "workspace/src/data_structure/array_and_string/trailing_zeroes.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("trailingZeroes", "[data_structure][array_and_string][trailing_zeroes]") {
    using namespace ns_data_structure_array_and_string_trailing_zeroes;
    Solution sol;
    REQUIRE(sol.trailingZeroes(3) == 0);
    REQUIRE(sol.trailingZeroes(5) == 1);
    REQUIRE(sol.trailingZeroes(25) == 6);
}
