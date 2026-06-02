// LeetCode 128 - Longest Consecutive Sequence
// Difficulty: Medium | Category: Hash Map/Set
// https://leetcode.com/problems/longest-consecutive-sequence/
#include <algorithm>
#include <unordered_set>
#include <vector>
namespace ns_data_structure_hash_map_set_128_longest_consecutive_sequence {

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set;
        for (auto num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {

            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
// @lc code=end

}  // namespace ns_data_structure_hash_map_set_128_longest_consecutive_sequence
