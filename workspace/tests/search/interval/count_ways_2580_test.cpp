#include "workspace/src/search/interval/count_ways_to_group_overlapping_ranges_2580.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("countWays2580", "[search][interval][count_ways]") {
    using namespace ns_search_interval_2580_count_ways_to_group_overlapping_ranges;
    Solution sol;
    SECTION("4 ranges 2 groups") {
        std::vector<std::vector<int>> ranges = {{1,3},{10,20},{2,5},{4,8}};
        REQUIRE(sol.countWays(ranges) == 4);
    }
    SECTION("two overlapping") {
        std::vector<std::vector<int>> ranges = {{1,3},{1,4}};
        REQUIRE(sol.countWays(ranges) == 2);
    }
}
