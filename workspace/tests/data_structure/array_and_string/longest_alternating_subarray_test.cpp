#include "workspace/src/data_structure/array_and_string/longest_alternating_subarray.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("longestAlternatingSubarray", "[data_structure][array_and_string][las]") {
    using namespace ns_data_structure_array_and_string_longest_alternating_subarray;
    Solution sol;
    SECTION("basic") {
        std::vector<int> nums = {3, 2, 5, 4};
        REQUIRE(sol.longestAlternatingSubarray(nums, 5) == 3);
    }
    SECTION("threshold too low") {
        std::vector<int> nums = {1, 2};
        REQUIRE(sol.longestAlternatingSubarray(nums, 1) == 0);
    }
}
