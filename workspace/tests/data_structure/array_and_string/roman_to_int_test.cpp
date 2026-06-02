#include "workspace/src/data_structure/array_and_string/roman_to_int.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("romanToInt", "[data_structure][array_and_string][roman_to_int]") {
    using namespace ns_data_structure_array_and_string_roman_to_int;
    Solution sol;
    REQUIRE(sol.romanToInt("III") == 3);
    REQUIRE(sol.romanToInt("IX") == 9);
    REQUIRE(sol.romanToInt("LVIII") == 58);
    REQUIRE(sol.romanToInt("MCMXCIV") == 1994);
}
