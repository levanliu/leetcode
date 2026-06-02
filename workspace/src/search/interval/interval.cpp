#include <algorithm>
#include <vector>

namespace ns_search_interval {

class Solution {
public:
    // ---- Merge Intervals ------------------------------------------------
    // Given a list of intervals, merge all overlapping ones.  O(n log n)
    // Example: [[1,3],[2,6],[8,10]] → [[1,6],[8,10]]
    static std::vector<std::vector<int>> mergeIntervals(
        std::vector<std::vector<int>> intervals) {
        if (intervals.empty())
            return {};
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < static_cast<int>(intervals.size()); ++i) {
            if (intervals[i][0] <= result.back()[1])
                result.back()[1] = std::max(result.back()[1], intervals[i][1]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }

    // ---- Insert Interval ------------------------------------------------
    // Insert newInterval into sorted non-overlapping intervals, merge if needed.
    // O(n)
    static std::vector<std::vector<int>> insertInterval(
        std::vector<std::vector<int>> intervals, std::vector<int> newInterval) {
        std::vector<std::vector<int>> result;
        int i = 0, n = static_cast<int>(intervals.size());
        // Add all intervals that end before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0])
            result.push_back(intervals[i++]);
        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            ++i;
        }
        result.push_back(newInterval);
        // Add remaining
        while (i < n)
            result.push_back(intervals[i++]);
        return result;
    }

    // ---- Non-overlapping Intervals (minimum removals) -------------------
    // Minimum number of intervals to remove to make the rest non-overlapping.
    // Greedy: sort by end time, keep greedily.  O(n log n)
    static int eraseOverlapIntervals(std::vector<std::vector<int>> intervals) {
        if (intervals.empty())
            return 0;
        std::sort(intervals.begin(), intervals.end(),
                  [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int removed = 0, end = intervals[0][1];
        for (int i = 1; i < static_cast<int>(intervals.size()); ++i) {
            if (intervals[i][0] < end)
                ++removed;
            else
                end = intervals[i][1];
        }
        return removed;
    }

    // ---- Meeting Rooms II -----------------------------------------------
    // Minimum number of conference rooms needed.  O(n log n)
    static int minMeetingRooms(std::vector<std::vector<int>> intervals) {
        std::vector<int> starts, ends;
        for (auto& iv : intervals) {
            starts.push_back(iv[0]);
            ends.push_back(iv[1]);
        }
        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());
        int rooms = 0, maxRooms = 0, j = 0;
        for (int i = 0; i < static_cast<int>(starts.size()); ++i) {
            if (starts[i] < ends[j])
                ++rooms;
            else {
                ++j;
            }
            maxRooms = std::max(maxRooms, rooms);
        }
        return maxRooms;
    }
};

}  // namespace ns_search_interval
