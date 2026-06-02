#include "workspace/src/data_structure/array_and_string/fraction_to_decimal.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("fractionToDecimal", "[data_structure][array_and_string][fraction_to_decimal]") {
    using namespace ns_data_structure_array_and_string_fraction_to_decimal;
    Solution sol;
    REQUIRE(sol.fractionToDecimal(1, 2) == "0.5");
    REQUIRE(sol.fractionToDecimal(4, 3) == "1.(3)");
    REQUIRE(sol.fractionToDecimal(1, 3) == "0.(3)");
    REQUIRE(sol.fractionToDecimal(2, 1) == "2");
}
