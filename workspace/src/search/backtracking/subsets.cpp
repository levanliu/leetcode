#include <vector>
namespace ns_search_backtracking_subsets {

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;

        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            std::vector<int> res;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    res.push_back(nums[j]);
            }
            ans.push_back(res);
        }

        return ans;
    }
};
}  // namespace ns_search_backtracking_subsets
