#include "workspace/src/search/interval/interval.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("mergeIntervals", "[search][interval]") {
    REQUIRE(mergeIntervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}}) ==
            std::vector<std::vector<int>>{{1, 6}, {8, 10}, {15, 18}});
    REQUIRE(mergeIntervals({{1, 4}, {4, 5}}) ==
            std::vector<std::vector<int>>{{1, 5}});
    REQUIRE(mergeIntervals({}).empty());
}

TEST_CASE("insertInterval", "[search][interval]") {
    REQUIRE(insertInterval({{1, 3}, {6, 9}}, {2, 5}) ==
            std::vector<std::vector<int>>{{1, 5}, {6, 9}});
    REQUIRE(
        insertInterval({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}) ==
        std::vector<std::vector<int>>{{1, 2}, {3, 10}, {12, 16}});
}

TEST_CASE("eraseOverlapIntervals", "[search][interval]") {
    REQUIRE(eraseOverlapIntervals({{1, 2}, {2, 3}, {3, 4}, {1, 3}}) == 1);
    REQUIRE(eraseOverlapIntervals({{1, 2}, {1, 2}, {1, 2}}) == 2);
    REQUIRE(eraseOverlapIntervals({{1, 2}, {2, 3}}) == 0);
}

TEST_CASE("minMeetingRooms", "[search][interval]") {
    REQUIRE(minMeetingRooms({{0, 30}, {5, 10}, {15, 20}}) == 2);
    REQUIRE(minMeetingRooms({{7, 10}, {2, 4}}) == 1);
}
