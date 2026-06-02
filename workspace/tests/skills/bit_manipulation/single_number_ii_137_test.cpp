#include "workspace/src/skills/bit_manipulation/single_number_ii_137.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("singleNumberII", "[skills][bit_manipulation][single_number_ii]") {
    using namespace ns_skills_bit_manipulation_137_single_number_ii;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {2, 2, 3, 2};
        REQUIRE(sol.singleNumber(nums) == 3);
    }
    SECTION("another") {
        std::vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
        REQUIRE(sol.singleNumber(nums) == 99);
    }
}
