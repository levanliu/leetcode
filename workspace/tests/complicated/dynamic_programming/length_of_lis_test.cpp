#include "workspace/src/complicated/dynamic_programming/length_of_lis.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("findPeakElement (in length_of_lis)", "[complicated][dp][length_of_lis]") {
    using namespace ns_complicated_dynamic_programming_length_of_lis;
    Solution sol;
    SECTION("ascending then descending") {
        std::vector<int> nums = {1, 2, 3, 1};
        REQUIRE(sol.findPeakElement(nums) == 2);
    }
    SECTION("single element") {
        std::vector<int> nums = {1};
        REQUIRE(sol.findPeakElement(nums) == 0);
    }
    SECTION("two elements descending") {
        std::vector<int> nums = {2, 1};
        REQUIRE(sol.findPeakElement(nums) == 0);
    }
}
