#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        int maxRes = dp[0];
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1],0) + nums[i];
            maxRes = max(dp[i],maxRes);
        }
        return maxRes;

    }
};