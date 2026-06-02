#include <utility>
#include <vector>
namespace ns_data_structure_array_and_string_spiral_order {

class Solution {
public:
    typedef std::pair<int, int> PII;
    bool st[110][110];
    std::vector<int> res;
    void dfs(std::vector<std::vector<int>>& matrix, int x, int y, bool isDown) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || st[x][y])
            return;

        int dx[2] = {1, -1};
        int dy[2] = {1, -1};
        st[x][y] = true;
        res.push_back(matrix[x][y]);
        if (isDown) {
            dfs(matrix, x, y + dy[0], true);
            dfs(matrix, x + dx[0], y, true);
            dfs(matrix, x, y + dy[1], true);
            dfs(matrix, x + dx[1], y, false);
        } else {
            dfs(matrix, x + dx[1], y, false);
            dfs(matrix, x, y + dy[0], true);
        }
    }
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        memset(st, 0, sizeof st);
        dfs(matrix, 0, 0, true);
        return res;
    }
};
}  // namespace ns_data_structure_array_and_string_spiral_order
