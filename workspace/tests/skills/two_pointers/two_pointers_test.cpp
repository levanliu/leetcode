#include <catch2/catch_test_macros.hpp>
#include "workspace/src/skills/two_pointers/two_pointers.h"

TEST_CASE("TwoPointers", "[skills][two_pointers]") {
    TwoPointers tp;

    SECTION("twoSumSorted found") {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        auto [l, r] = tp.twoSumSorted(nums, 9);
        REQUIRE(l == 3);
        REQUIRE(r == 4);
    }

    SECTION("twoSumSorted not found") {
        std::vector<int> nums = {1, 2, 3};
        auto [l, r] = tp.twoSumSorted(nums, 10);
        REQUIRE(l == -1);
        REQUIRE(r == -1);
    }

    SECTION("removeDuplicates") {
        std::vector<int> nums = {1, 1, 2, 3, 3, 4};
        int newLen = tp.removeDuplicates(nums);
        REQUIRE(newLen == 4);
        REQUIRE(nums[0] == 1);
        REQUIRE(nums[1] == 2);
        REQUIRE(nums[2] == 3);
        REQUIRE(nums[3] == 4);
    }

    SECTION("moveZeros") {
        std::vector<int> nums = {0, 1, 0, 3, 12};
        tp.moveZeros(nums);
        REQUIRE(nums == std::vector<int>{1, 3, 12, 0, 0});
    }
}
