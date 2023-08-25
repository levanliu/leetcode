#include<bits/stdc++.h>
using namespace std;
// 买卖股票的最佳时机 II
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int length = prices.size();
        int dp[length][2];
        // 初始条件
        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        for (int i = 1; i < length; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[length - 1][0];
    }
};