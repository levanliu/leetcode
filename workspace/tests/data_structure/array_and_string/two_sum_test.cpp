#include <catch2/catch_test_macros.hpp>
#include "workspace/src/data_structure/array_and_string/two_sum.cpp"

TEST_CASE("TwoSum basic cases", "[data_structure][array_and_string]") {
    TwoSum sol;

    SECTION("standard case") {
        std::vector<int> nums = {2, 7, 11, 15};
        auto res = sol.twoSum(nums, 9);
        REQUIRE(res.size() == 2);
        REQUIRE(res[0] == 0);
        REQUIRE(res[1] == 1);
    }

    SECTION("multiple candidates") {
        std::vector<int> nums = {3, 2, 4};
        auto res = sol.twoSum(nums, 6);
        REQUIRE(res.size() == 2);
        REQUIRE(res[0] == 1);
        REQUIRE(res[1] == 2);
    }

    SECTION("same element twice") {
        std::vector<int> nums = {3, 3};
        auto res = sol.twoSum(nums, 6);
        REQUIRE(res.size() == 2);
        REQUIRE(res[0] == 0);
        REQUIRE(res[1] == 1);
    }
}
