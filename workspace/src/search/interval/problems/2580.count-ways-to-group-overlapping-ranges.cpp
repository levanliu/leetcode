// LeetCode 2580 - Count Ways to Group Overlapping Ranges
// Difficulty: Medium | Category: Interval
// https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/

#include <vector>
#include <algorithm>

class Solution
{
public:
    static constexpr int mod = 1e9 + 7;
    int countWays(vector<vector<int>> &ranges)
    {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();
        long long res = 1;
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            int r = ranges[i][1];
            while (j < n && r > ranges[j][0])
            {
                r = max(r, ranges[j][1]);
                j++;
                res = res * 2 % mod;
            }
            i = j;
        }
        return res;
    }
};