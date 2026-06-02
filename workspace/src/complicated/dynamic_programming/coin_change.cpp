#include <algorithm>
#include <climits>
#include <vector>
namespace ns_complicated_dynamic_programming_coin_change {

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        int n = amount + 1;
        std::vector<int> dp(n, -1);
        dp[0] = 0;
        for (int c : coins) {
            if (c > amount)
                continue;
            dp[c] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            int cur = INT_MAX;
            for (int c : coins) {
                if (i - c >= 0 && dp[i - c] != -1)
                    cur = std::min(cur, dp[i - c] + 1);
            }
            if (cur != INT_MAX)
                dp[i] = cur;
        }
        return dp[amount];
    }
};
}  // namespace ns_complicated_dynamic_programming_coin_change
