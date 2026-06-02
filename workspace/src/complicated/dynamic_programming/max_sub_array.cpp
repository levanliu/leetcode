#include <algorithm>
#include <vector>
namespace ns_complicated_dynamic_programming_max_sub_array {

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        int maxRes = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = std::max(dp[i - 1], 0) + nums[i];
            maxRes = std::max(dp[i], maxRes);
        }
        return maxRes;
    }
};
}  // namespace ns_complicated_dynamic_programming_max_sub_array
