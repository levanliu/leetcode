#include "workspace/src/data_structure/array_and_string/is_happy.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("isHappy", "[data_structure][array_and_string][is_happy]") {
    using namespace ns_data_structure_array_and_string_is_happy;
    SECTION("happy number") {
        Solution sol;
        REQUIRE(sol.isHappy(19) == true);
    }
    SECTION("not happy") {
        Solution sol;
        REQUIRE(sol.isHappy(2) == false);
    }
    SECTION("happy 1") {
        Solution sol;
        REQUIRE(sol.isHappy(1) == true);
    }
}
