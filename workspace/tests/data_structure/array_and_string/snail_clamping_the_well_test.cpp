#include "workspace/src/data_structure/array_and_string/snail_clamping_the_well.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("snailClampingWell", "[data_structure][array_and_string][snail]") {
    using namespace ns_data_structure_array_and_string_snail;
    REQUIRE(Solution::daysToClimb(6) == 2);
    REQUIRE(Solution::daysToClimb(5) == 1);
    REQUIRE(Solution::daysToClimb(1) == 1);
    REQUIRE(Solution::daysToClimb(10) == 6);
}
