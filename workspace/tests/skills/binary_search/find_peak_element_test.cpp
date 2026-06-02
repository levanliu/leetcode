#include "workspace/src/skills/binary_search/find_peak_element.cpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("findPeakElement", "[skills][binary_search][find_peak_element]") {
    using namespace ns_skills_binary_search_find_peak_element;
    Solution sol;
    SECTION("ascending then descending") {
        std::vector<int> nums = {1, 2, 3, 1};
        int peak = sol.findPeakElement(nums);
        REQUIRE(peak == 2);
    }
    SECTION("multiple peaks") {
        std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
        int peak = sol.findPeakElement(nums);
        // Valid peak: nums[peak] > nums[peak-1] (or boundary) and > nums[peak+1] (or boundary)
        bool valid = true;
        if (peak > 0) valid = valid && nums[peak] > nums[peak-1];
        if (peak < (int)nums.size()-1) valid = valid && nums[peak] > nums[peak+1];
        REQUIRE(valid);
    }
    SECTION("single element") {
        std::vector<int> nums = {1};
        REQUIRE(sol.findPeakElement(nums) == 0);
    }
}
