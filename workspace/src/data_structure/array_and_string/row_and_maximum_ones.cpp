#include <vector>
namespace ns_array_row_and_max_ones {

class Solution {
public:
    std::vector<int> rowAndMaximumOnes(std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        std::vector<int> res(2, -1);
        for (int i = 0; i < n; i++) {
            int onesCount = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    onesCount++;
                }
            }
            if (onesCount > res[1]) {
                res[1] = onesCount;
                res[0] = i;
            }
        }
        return res;
    }
};

}  // namespace ns_array_row_and_max_ones
