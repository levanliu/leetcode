#include "workspace/src/skills/two_pointers/three_sum.cpp"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <vector>

TEST_CASE("threeSum", "[skills][two_pointers][three_sum]") {
    using namespace ns_skills_two_pointers_three_sum;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
        auto result = sol.threeSum(nums);
        REQUIRE(result.size() == 2);
    }
    SECTION("all zeros") {
        std::vector<int> nums = {0, 0, 0};
        auto result = sol.threeSum(nums);
        REQUIRE(result.size() == 1);
        REQUIRE((result[0] == std::vector<int>{0, 0, 0}));
    }
    SECTION("no triplet") {
        std::vector<int> nums = {1, 2, 3};
        auto result = sol.threeSum(nums);
        REQUIRE(result.empty());
    }
}
