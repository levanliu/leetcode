// LeetCode 322 - Coin Change
// Difficulty: Medium | Category: Dynamic Programming
// https://leetcode.com/problems/coin-change/

#include <climits>
#include <vector>

namespace ns_dp_coin_change {

class Solution {
private:
    std::vector<int> count;

public:
    Solution(/* args */);
    ~Solution();
    int dp(std::vector<int>& coins, int rem);
    int coinChange(std::vector<int>& coins, int amount);
};

Solution::Solution(/* args */) {}

Solution::~Solution() {}

int Solution::dp(std::vector<int>& coins, int rem) {
    if (rem < 0)
        return -1;
    if (rem == 0)
        return 0;
    /**
     * 我们将每个子问题的答案存在一个数组中进行记忆化，如果下次还要计算这个问题的值直接从数组中取出返回即可，这样能保证每个子问题最多只被计算一次。
    */
    if (count[rem - 1] != 0)
        return count[rem - 1];
    int Min = INT_MAX;
    for (std::size_t i = 0; i < coins.size(); i++) {
        int res = dp(coins, rem - coins[i]);
        if (res >= 0 && res < Min) {
            Min = res + 1;
        }
    }
    count[rem - 1] = Min == INT_MAX ? -1 : Min;
    return count[rem - 1];
}

int Solution::coinChange(std::vector<int>& coins, int amount) {
    if (amount < 1)
        return 0;
    count.resize(amount);
    return dp(coins, amount);
}
}  // namespace ns_dp_coin_change
