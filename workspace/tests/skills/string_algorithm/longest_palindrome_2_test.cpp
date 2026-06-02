#include "workspace/src/skills/string_algorithm/longest_palindrome_2.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("longestPalindrome2", "[skills][string_algorithm][longest_palindrome_2]") {
    using namespace ns_string_longest_palindrome;
    Solution sol;
    SECTION("babad") {
        std::string result = sol.longestPalindrome("babad");
        REQUIRE((result == "bab" || result == "aba"));
    }
    SECTION("cbbd") {
        REQUIRE(sol.longestPalindrome("cbbd") == "bb");
    }
    SECTION("single char") {
        REQUIRE(sol.longestPalindrome("a") == "a");
    }
}
