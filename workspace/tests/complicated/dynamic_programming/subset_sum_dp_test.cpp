#include "workspace/src/complicated/dynamic_programming/subset_sum_dp.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("subsetSumDP", "[complicated][dp][subset_sum_dp]") {
    using namespace ns_complicated_dynamic_programming_subset_sum_dp;
    SECTION("two subsets") {
        std::vector<int> arr = {1, 2, 3, 4};
        auto result = Solution::findSubsets(arr, 5);
        REQUIRE(result.size() == 2);
    }
    SECTION("no subset") {
        std::vector<int> arr = {2, 4};
        auto result = Solution::findSubsets(arr, 3);
        REQUIRE(result.empty());
    }
    SECTION("zero target empty array") {
        std::vector<int> arr = {};
        auto result = Solution::findSubsets(arr, 0);
        REQUIRE(result.empty());
    }
}
