#include "workspace/src/skills/two_pointers/four_sum_18.cpp"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <vector>

TEST_CASE("fourSum18", "[skills][two_pointers][four_sum]") {
    using namespace ns_skills_two_pointers_18_4sum;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {1, 0, -1, 0, -2, 2};
        auto result = sol.fourSum(nums, 0);
        REQUIRE(result.size() == 3);
    }
    SECTION("empty result") {
        std::vector<int> nums = {2, 2, 2, 2};
        auto result = sol.fourSum(nums, 1);
        REQUIRE(result.empty());
    }
}
