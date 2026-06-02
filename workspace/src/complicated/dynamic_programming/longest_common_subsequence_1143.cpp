#include <algorithm>
#include <string>
// LeetCode 1143 - Longest Common Subsequence
// Difficulty: Medium | Category: Dynamic Programming
// https://leetcode.com/problems/longest-common-subsequence/

// #include<iostream>
namespace ns_complicated_dynamic_programming_1143_longest_common_subsequence {

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        //f[i][j]
        int f[1010][1010];

        for (std::size_t i = 0; i <= text1.size(); i++) {
            f[i][0] = 0;
        }
        for (std::size_t i = 0; i <= text2.size(); i++) {
            f[0][i] = 0;
        }
        for (std::size_t i = 1; i <= text1.size(); i++) {
            for (std::size_t j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[text1.size()][text2.size()];
    }
};
// @lc code=end

}  // namespace ns_complicated_dynamic_programming_1143_longest_common_subsequence
