// Subset Sum via backtracking: find all subsets summing to target.
#include <vector>

namespace ns_search_backtracking_subset_sum {

class Solution {
public:
    static std::vector<std::vector<int>> findSubsets(
        const std::vector<int>& arr, int target) {
        std::vector<std::vector<int>> results;
        std::vector<int> current;
        backtrack(arr, target, 0, current, results);
        return results;
    }

private:
    static void backtrack(const std::vector<int>& arr, int remaining, int idx,
                          std::vector<int>& current,
                          std::vector<std::vector<int>>& results) {
        if (remaining == 0) {
            results.push_back(current);
            return;
        }
        if (idx == static_cast<int>(arr.size())) {
            return;
        }
        // Skip arr[idx]
        backtrack(arr, remaining, idx + 1, current, results);
        // Take arr[idx]
        if (arr[idx] <= remaining) {
            current.push_back(arr[idx]);
            backtrack(arr, remaining - arr[idx], idx + 1, current, results);
            current.pop_back();
        }
    }
};

}  // namespace ns_search_backtracking_subset_sum
