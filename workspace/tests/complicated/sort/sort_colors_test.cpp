#include "workspace/src/complicated/sort/sort_colors.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("sortColors", "[complicated][sort][sort_colors]") {
    using namespace ns_complicated_sort_sort_colors;
    Solution sol;
    SECTION("mixed") {
        std::vector<int> nums = {2, 0, 2, 1, 1, 0};
        sol.sortColors(nums);
        REQUIRE((nums == std::vector<int>{0, 0, 1, 1, 2, 2}));
    }
    SECTION("already sorted") {
        std::vector<int> nums = {0, 1, 2};
        sol.sortColors(nums);
        REQUIRE((nums == std::vector<int>{0, 1, 2}));
    }
    SECTION("all same") {
        std::vector<int> nums = {1, 1, 1};
        sol.sortColors(nums);
        REQUIRE((nums == std::vector<int>{1, 1, 1}));
    }
}
