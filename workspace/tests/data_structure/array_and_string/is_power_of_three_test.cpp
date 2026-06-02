#include "workspace/src/data_structure/array_and_string/is_power_of_three.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("isPowerOfThree", "[data_structure][array_and_string][is_power_of_three]") {
    using namespace ns_data_structure_array_and_string_is_power_of_three;
    Solution sol;
    REQUIRE(sol.isPowerOfThree(27) == true);
    REQUIRE(sol.isPowerOfThree(0) == false);
    REQUIRE(sol.isPowerOfThree(9) == true);
    REQUIRE(sol.isPowerOfThree(45) == false);
}
