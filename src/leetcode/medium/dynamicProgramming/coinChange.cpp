#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int csize = coins.size();
        int n = 10010;
        int dp[n];
        memset(dp,-1,sizeof dp);
        dp[0] = 0;
        for(int c:coins){
            if(c > n)
                continue;
            dp[c] = 1;
        }
        for(int i=1;i<=amount;i++){
            int cur = INT_MAX;
            for(int c:coins){
                if(i-c>=0 && dp[i-c]!=-1)
                    cur = min(cur,dp[i-c]+1);
            }
            if(cur != INT_MAX)
                dp[i] = cur;
        }
        return dp[amount];
    }
};