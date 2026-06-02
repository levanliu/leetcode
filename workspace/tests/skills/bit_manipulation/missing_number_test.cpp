#include "workspace/src/skills/bit_manipulation/missing_number.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("missingNumber", "[skills][bit_manipulation][missing_number]") {
    using namespace ns_skills_bit_manipulation_missing_number;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {3, 0, 1};
        REQUIRE(sol.missingNumber(nums) == 2);
    }
    SECTION("another") {
        std::vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
        REQUIRE(sol.missingNumber(nums) == 8);
    }
    SECTION("zero missing") {
        std::vector<int> nums = {1};
        REQUIRE(sol.missingNumber(nums) == 0);
    }
}
