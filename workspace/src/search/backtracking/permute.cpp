#include <vector>
namespace ns_search_backtracking_permute {

class Solution {
public:
    std::vector<std::vector<int>> ans;
    static const int N = 7;
    int path[N];
    bool st[N];

    void dfs(int u, std::vector<int>& nums) {

        if (u == static_cast<int>(nums.size())) {
            std::vector<int> res(path, path + nums.size());
            ans.push_back(res);
            return;
        }

        for (std::size_t i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                path[u] = nums[i];
                st[i] = true;
                dfs(u + 1, nums);
                st[i] = false;
            }
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
}  // namespace ns_search_backtracking_permute
