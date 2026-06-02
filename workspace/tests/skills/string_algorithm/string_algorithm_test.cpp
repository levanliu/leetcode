#include "workspace/src/skills/string_algorithm/string_algorithm.cpp"
#include <algorithm>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("kmpSearch", "[skills][string_algorithm]") {
    REQUIRE(kmpSearch("abababab", "abab") == std::vector<int>{0, 2, 4});
    REQUIRE(kmpSearch("hello", "xyz").empty());
    REQUIRE(kmpSearch("helloworld", "world") == std::vector<int>{5});
    REQUIRE(kmpSearch("abc", "").empty());
}

TEST_CASE("longestPalindrome", "[skills][string_algorithm]") {
    REQUIRE(longestPalindrome("babad").size() == 3);  // "bab" or "aba"
    REQUIRE(longestPalindrome("cbbd") == "bb");
    REQUIRE(longestPalindrome("a") == "a");
    REQUIRE(longestPalindrome("ac").size() == 1);
}

TEST_CASE("isPalindrome", "[skills][string_algorithm]") {
    REQUIRE(isPalindrome("racecar"));
    REQUIRE(isPalindrome("a"));
    REQUIRE_FALSE(isPalindrome("hello"));
}

TEST_CASE("StringHash", "[skills][string_algorithm]") {
    StringHash sh("abcabc");
    // "abc" at [0..2] and [3..5] should have the same hash
    REQUIRE(sh.get(0, 2) == sh.get(3, 5));
    REQUIRE(sh.get(0, 0) != sh.get(1, 1));  // 'a' != 'b'
}

TEST_CASE("groupAnagrams", "[skills][string_algorithm]") {
    auto groups = groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
    REQUIRE(groups.size() == 3);
}

TEST_CASE("lengthOfLongestSubstring", "[skills][string_algorithm]") {
    REQUIRE(lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(lengthOfLongestSubstring("") == 0);
}
