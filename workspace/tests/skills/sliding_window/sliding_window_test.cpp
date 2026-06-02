#include "workspace/src/skills/sliding_window/sliding_window.cpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("SlidingWindow", "[skills][sliding_window]") {
    ns_skills_sliding_window::Solution sw;

    SECTION("maxSumSubarray") {
        std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        REQUIRE(sw.maxSumSubarray(nums, 3) == 16);
    }

    SECTION("lengthOfLongestSubstring") {
        REQUIRE(sw.lengthOfLongestSubstring("abcabcbb") == 3);
        REQUIRE(sw.lengthOfLongestSubstring("bbbbb") == 1);
        REQUIRE(sw.lengthOfLongestSubstring("pwwkew") == 3);
        REQUIRE(sw.lengthOfLongestSubstring("") == 0);
    }

    SECTION("maxSlidingWindow") {
        std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        auto res = sw.maxSlidingWindow(nums, 3);
        REQUIRE(res == std::vector<int>{3, 3, 5, 5, 6, 7});
    }
}
