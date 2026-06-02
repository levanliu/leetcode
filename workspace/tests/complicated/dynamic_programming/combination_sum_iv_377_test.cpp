#include "workspace/src/complicated/dynamic_programming/combination_sum_iv_377.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("combinationSum4", "[complicated][dp][combination_sum_iv]") {
    using namespace ns_complicated_dynamic_programming_377_combination_sum_iv;
    SECTION("basic") {
        Solution sol;
        std::vector<int> nums = {1, 2, 3};
        REQUIRE(sol.combinationSum4(nums, 4) == 7);
    }
    SECTION("no solution") {
        Solution sol;
        std::vector<int> nums = {9};
        REQUIRE(sol.combinationSum4(nums, 3) == 0);
    }
}
