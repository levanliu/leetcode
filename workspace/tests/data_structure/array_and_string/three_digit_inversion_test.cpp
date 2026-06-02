#include "workspace/src/data_structure/array_and_string/three_digit_inversion.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("invertThreeDigits", "[data_structure][array_and_string][three_digit_inversion]") {
    using namespace ns_data_structure_array_and_string_three_digit_inversion;
    REQUIRE(Solution::invertThreeDigits(123) == 321);
    REQUIRE(Solution::invertThreeDigits(100) == 1);
    REQUIRE(Solution::invertThreeDigits(321) == 123);
}
