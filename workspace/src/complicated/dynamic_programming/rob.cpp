#include <algorithm>
#include <vector>
namespace ns_complicated_dynamic_programming_rob {

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
}  // namespace ns_complicated_dynamic_programming_rob
