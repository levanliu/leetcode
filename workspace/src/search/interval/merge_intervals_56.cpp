// LeetCode 56 - Merge Intervals
// Difficulty: Medium | Category: Interval
// https://leetcode.com/problems/merge-intervals/

#include <algorithm>
#include <vector>
namespace ns_search_interval_56_merge_intervals {


class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            int r = intervals[i][1];
            while (j < n && r >= intervals[j][0])
            {
                r = std::max(r, intervals[j][1]);
                j++;
            }
            res.push_back({intervals[i][0], r});
            i = j;
        }
        return res;
    }
};
} // namespace ns_search_interval_56_merge_intervals
