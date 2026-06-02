#include "workspace/src/skills/sliding_window/length_of_longest_substring.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("lengthOfLongestSubstring", "[skills][sliding_window][length_of_longest_substring]") {
    using namespace ns_skills_sliding_window_length_of_longest_substring;
    Solution sol;
    REQUIRE(sol.lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(sol.lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(sol.lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(sol.lengthOfLongestSubstring("") == 0);
}
