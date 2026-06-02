// Subset Sum — enumerate all subsets with a given sum using DP reconstruction
#include <vector>

namespace ns_complicated_dynamic_programming_subset_sum_dp {

class Solution {
public:
    // Returns all subsets of arr whose elements sum to targetSum.
    static std::vector<std::vector<int>> findSubsets(
        const std::vector<int>& arr, int targetSum) {
        int n = static_cast<int>(arr.size());
        if (targetSum < 0 || n == 0) {
            return {};
        }
        // dp[i][j] == true iff sum j is achievable using arr[0..i-1]
        std::vector<std::vector<bool>> dp(
            n + 1, std::vector<bool>(targetSum + 1, false));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= targetSum; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        std::vector<std::vector<int>> results;
        std::vector<int> current;
        reconstruct(arr, dp, n, targetSum, current, results);
        return results;
    }

private:
    static void reconstruct(const std::vector<int>& arr,
                            const std::vector<std::vector<bool>>& dp, int i,
                            int sum, std::vector<int>& current,
                            std::vector<std::vector<int>>& results) {
        if (sum == 0) {
            results.push_back(current);
            return;
        }
        if (i == 0) {
            return;
        }
        // Path without arr[i-1]
        if (dp[i - 1][sum]) {
            reconstruct(arr, dp, i - 1, sum, current, results);
        }
        // Path with arr[i-1]
        if (sum >= arr[i - 1] && dp[i - 1][sum - arr[i - 1]]) {
            current.push_back(arr[i - 1]);
            reconstruct(arr, dp, i - 1, sum - arr[i - 1], current, results);
            current.pop_back();
        }
    }
};

}  // namespace ns_complicated_dynamic_programming_subset_sum_dp
