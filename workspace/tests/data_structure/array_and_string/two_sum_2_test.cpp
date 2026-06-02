#include "workspace/src/data_structure/array_and_string/two_sum_2.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("twoSum2", "[data_structure][array_and_string][two_sum_2]") {
    using namespace ns_array_two_sum_stub;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {2, 7, 11, 15};
        auto r = sol.twoSum(nums, 9);
        REQUIRE((r == std::vector<int>{0, 1}));
    }
    SECTION("another") {
        std::vector<int> nums = {3, 2, 4};
        auto r = sol.twoSum(nums, 6);
        REQUIRE((r == std::vector<int>{1, 2}));
    }
}
