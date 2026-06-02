#include "workspace/src/skills/string_algorithm/longest_substring.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("longestSubstring", "[skills][string_algorithm][longest_substring]") {
    using namespace ns_string_longest_substring;
    Solution sol;
    REQUIRE(sol.lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(sol.lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(sol.lengthOfLongestSubstring("") == 0);
}
