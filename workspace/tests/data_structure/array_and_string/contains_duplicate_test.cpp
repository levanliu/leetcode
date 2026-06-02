#include "workspace/src/data_structure/array_and_string/contains_duplicate.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("containsDuplicate", "[data_structure][array_and_string][contains_duplicate]") {
    using namespace ns_data_structure_array_and_string_contains_duplicate;
    Solution sol;
    SECTION("has duplicate") {
        std::vector<int> nums = {1, 2, 3, 1};
        REQUIRE(sol.containsDuplicate(nums) == true);
    }
    SECTION("no duplicate") {
        std::vector<int> nums = {1, 2, 3, 4};
        REQUIRE(sol.containsDuplicate(nums) == false);
    }
}
