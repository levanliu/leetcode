#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

namespace ns_complicated_greedy {

class Solution {
public:
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int maxProfit(const std::vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {
            minPrice = std::min(minPrice, price);
            maxProfit = std::max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }

    // https://leetcode.com/problems/merge-intervals/
    std::vector<std::pair<int, int>> mergeIntervals(
        std::vector<std::pair<int, int>> intervals) {
        if (intervals.empty()) {
            return {};
        }
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::pair<int, int>> res = {intervals[0]};
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i].first <= res.back().second) {
                res.back().second =
                    std::max(res.back().second, intervals[i].second);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

    // https://leetcode.com/problems/jump-game/
    bool canJump(const std::vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = std::max(maxReach, i + nums[i]);
        }
        return true;
    }
};

}  // namespace ns_complicated_greedy
