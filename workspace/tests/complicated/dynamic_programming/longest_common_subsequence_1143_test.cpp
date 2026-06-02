#include "workspace/src/complicated/dynamic_programming/longest_common_subsequence_1143.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("longestCommonSubsequence", "[complicated][dp][lcs]") {
    using namespace ns_complicated_dynamic_programming_1143_longest_common_subsequence;
    Solution sol;
    REQUIRE(sol.longestCommonSubsequence("abcde", "ace") == 3);
    REQUIRE(sol.longestCommonSubsequence("abc", "abc") == 3);
    REQUIRE(sol.longestCommonSubsequence("abc", "def") == 0);
}
