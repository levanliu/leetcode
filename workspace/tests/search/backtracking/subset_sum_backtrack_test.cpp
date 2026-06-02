#include "workspace/src/search/backtracking/subset_sum_backtrack.cpp"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <vector>

TEST_CASE("subsetSumBacktrack", "[search][backtracking][subset_sum_backtrack]") {
    using namespace ns_search_backtracking_subset_sum;
    SECTION("two subsets") {
        std::vector<int> arr = {3, 1, 2};
        auto result = Solution::findSubsets(arr, 3);
        REQUIRE(result.size() == 2);
    }
    SECTION("no subset") {
        std::vector<int> arr = {2, 4};
        auto result = Solution::findSubsets(arr, 3);
        REQUIRE(result.empty());
    }
}
