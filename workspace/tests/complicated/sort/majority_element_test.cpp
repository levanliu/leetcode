#include "workspace/src/complicated/sort/majority_element.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("majorityElement", "[complicated][sort][majority_element]") {
    using namespace ns_complicated_sort_majority_element;
    SECTION("basic") {
        std::vector<int> nums = {3, 2, 3};
        Solution sol;
        REQUIRE(sol.majorityElement(nums) == 3);
    }
    SECTION("larger array") {
        std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        Solution sol;
        REQUIRE(sol.majorityElement(nums) == 2);
    }
}
