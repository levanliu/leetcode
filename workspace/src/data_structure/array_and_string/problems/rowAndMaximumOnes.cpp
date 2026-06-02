#include <vector>

using namespace std;

class solution {
   public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> res(2, -1);
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
