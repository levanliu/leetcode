#include <vector>
namespace ns_data_structure_array_and_string_is_valid_soduku {

class Solution {
public:
    bool isValidSoduku(std::vector<std::vector<char>>& board) {
        int m = board.size();

        // row col cell  indicate the i row, j col, k cell has val?
        std::vector<std::vector<int>> row(m, std::vector<int>(m, 0));
        std::vector<std::vector<int>> col(m, std::vector<int>(m, 0));
        std::vector<std::vector<int>> cell(m, std::vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int val = board[i][j] - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][val] != 0 || col[j][val] != 0 || cell[k][val] != 0) {
                    return false;
                }
                row[i][val] = col[j][val] = cell[k][val] = 1;
            }
        }
        return true;
    }
};

}  // namespace ns_data_structure_array_and_string_is_valid_soduku
