#include <catch2/catch_test_macros.hpp>
#include "workspace/src/complicated/greedy/greedy.h"

TEST_CASE("Greedy", "[complicated][greedy]") {
    Greedy g;

    SECTION("maxProfit") {
        REQUIRE(g.maxProfit({7, 1, 5, 3, 6, 4}) == 5);
        REQUIRE(g.maxProfit({7, 6, 4, 3, 1}) == 0);
        REQUIRE(g.maxProfit({1}) == 0);
    }

    SECTION("mergeIntervals") {
        std::vector<std::pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        auto res = g.mergeIntervals(intervals);
        REQUIRE(res.size() == 3);
        REQUIRE(res[0] == std::make_pair(1, 6));
        REQUIRE(res[1] == std::make_pair(8, 10));
        REQUIRE(res[2] == std::make_pair(15, 18));
    }

    SECTION("canJump") {
        REQUIRE(g.canJump({2, 3, 1, 1, 4}));
        REQUIRE_FALSE(g.canJump({3, 2, 1, 0, 4}));
        REQUIRE(g.canJump({0}));
    }
}
