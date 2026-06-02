#include "workspace/src/complicated/dynamic_programming/max_sub_array.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("maxSubArray", "[complicated][dp][max_sub_array]") {
    using namespace ns_complicated_dynamic_programming_max_sub_array;
    Solution sol;
    SECTION("mixed") {
        std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        REQUIRE(sol.maxSubArray(nums) == 6);
    }
    SECTION("all negative") {
        std::vector<int> nums = {-1};
        REQUIRE(sol.maxSubArray(nums) == -1);
    }
    SECTION("single positive") {
        std::vector<int> nums = {5};
        REQUIRE(sol.maxSubArray(nums) == 5);
    }
}
