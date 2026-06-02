#pragma once
#include <algorithm>
#include <climits>
#include <string>
#include <vector>

namespace ns_complicated_dynamic_programming {

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int a = 0;
        int b = 1;
        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    int knapsack01(const std::vector<int>& weights,
                   const std::vector<int>& values, int capacity) {
        int n = (int)weights.size();
        std::vector<int> dp(capacity + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = capacity; j >= weights[i]; j--) {
                dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
        return dp[capacity];
    }

    int lcs(const std::string& s1, const std::string& s2) {
        int m = (int)s1.size();
        int n = (int)s2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (s1[i - 1] == s2[j - 1])
                               ? dp[i - 1][j - 1] + 1
                               : std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }

    int coinChange(const std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

}  // namespace ns_complicated_dynamic_programming
