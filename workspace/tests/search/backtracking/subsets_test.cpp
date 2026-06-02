#include "workspace/src/search/backtracking/subsets.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("subsets", "[search][backtracking][subsets]") {
    using namespace ns_search_backtracking_subsets;
    Solution sol;
    SECTION("3 elements") {
        std::vector<int> nums = {1, 2, 3};
        auto result = sol.subsets(nums);
        REQUIRE(result.size() == 8);
    }
    SECTION("empty") {
        std::vector<int> nums = {};
        auto result = sol.subsets(nums);
        REQUIRE(result.size() == 1);  // only the empty subset
    }
}
