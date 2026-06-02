#include "workspace/src/skills/bit_manipulation/single_number.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("singleNumber", "[skills][bit_manipulation][single_number]") {
    using namespace ns_skills_bit_manipulation_single_number;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {2, 2, 1};
        REQUIRE(sol.singleNumber(nums) == 1);
    }
    SECTION("another") {
        std::vector<int> nums = {4, 1, 2, 1, 2};
        REQUIRE(sol.singleNumber(nums) == 4);
    }
}
