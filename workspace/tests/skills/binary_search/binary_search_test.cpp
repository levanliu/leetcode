#include <catch2/catch_test_macros.hpp>
#include "workspace/src/skills/binary_search/binary_search.h"

TEST_CASE("BinarySearch", "[skills][binary_search]") {
    BinarySearch bs;
    std::vector<int> nums = {1, 3, 5, 7, 9, 11};

    SECTION("search found") {
        REQUIRE(bs.search(nums, 7) == 3);
        REQUIRE(bs.search(nums, 1) == 0);
        REQUIRE(bs.search(nums, 11) == 5);
    }

    SECTION("search not found") {
        REQUIRE(bs.search(nums, 4) == -1);
        REQUIRE(bs.search(nums, 0) == -1);
        REQUIRE(bs.search(nums, 12) == -1);
    }

    SECTION("lowerBound") {
        REQUIRE(bs.lowerBound(nums, 5) == 2);
        REQUIRE(bs.lowerBound(nums, 6) == 3);
        REQUIRE(bs.lowerBound(nums, 0) == 0);
        REQUIRE(bs.lowerBound(nums, 12) == 6);
    }

    SECTION("upperBound") {
        REQUIRE(bs.upperBound(nums, 5) == 3);
        REQUIRE(bs.upperBound(nums, 6) == 3);
        REQUIRE(bs.upperBound(nums, 11) == 6);
    }
}
