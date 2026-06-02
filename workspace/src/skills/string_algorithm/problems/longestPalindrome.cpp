#include <iostream>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof dp);
        int start = 0, maxLength = 1;
        for (int right = 1; right < s.size(); right++)
        {
            for (int left = 0; left < right; left++)
            {
                if (s[right] != s[left])
                    continue;
                if (right - left <= 2)
                    dp[left][right] = true;
                else
                    dp[left][right] = dp[left + 1][right - 1];

                if (dp[left][right] && maxLength < right - left + 1)
                {
                    maxLength = right - left + 1;
                    start = left;
                }
            }
        }
        return s.substr(start, maxLength);
    }
};