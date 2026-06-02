#include "workspace/src/search/interval/merge_intervals_56.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("mergeIntervals", "[search][interval][merge_intervals]") {
    using namespace ns_search_interval_56_merge_intervals;
    Solution sol;
    SECTION("basic") {
        std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        auto result = sol.merge(intervals);
        REQUIRE(result.size() == 3);
        REQUIRE((result[0] == std::vector<int>{1,6}));
        REQUIRE((result[1] == std::vector<int>{8,10}));
        REQUIRE((result[2] == std::vector<int>{15,18}));
    }
    SECTION("all overlapping") {
        std::vector<std::vector<int>> intervals = {{1,4},{4,5}};
        auto result = sol.merge(intervals);
        REQUIRE(result.size() == 1);
        REQUIRE((result[0] == std::vector<int>{1,5}));
    }
}
