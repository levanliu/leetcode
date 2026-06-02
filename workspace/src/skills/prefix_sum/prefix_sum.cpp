#include <vector>

namespace ns_skills_prefix_sum_1d {

class Solution {
    std::vector<int> ps;

public:
    explicit Solution(const std::vector<int>& nums) {
        ps.resize(nums.size() + 1, 0);
        for (int i = 0; i < (int)nums.size(); i++)
            ps[i + 1] = ps[i] + nums[i];
    }
    // Sum of nums[l..r] inclusive (0-indexed)
    int query(int l, int r) const { return ps[r + 1] - ps[l]; }
};

}  // namespace ns_skills_prefix_sum_1d

namespace ns_skills_prefix_sum_2d {

class Solution {
    std::vector<std::vector<int>> ps;

public:
    explicit Solution(const std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(), n = m ? (int)matrix[0].size() : 0;
        ps.assign(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                ps[i][j] = matrix[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] -
                           ps[i - 1][j - 1];
    }
    // Sum of submatrix (r1,c1) to (r2,c2) inclusive (0-indexed)
    int query(int r1, int c1, int r2, int c2) const {
        return ps[r2 + 1][c2 + 1] - ps[r1][c2 + 1] - ps[r2 + 1][c1] +
               ps[r1][c1];
    }
};

}  // namespace ns_skills_prefix_sum_2d
