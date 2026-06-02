#include <algorithm>
#include <vector>
namespace ns_complicated_dynamic_programming_max_profit {

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], -prices[i]);
        }
        return dp[n - 1][0];
    }
};
}  // namespace ns_complicated_dynamic_programming_max_profit
