#include <functional>
#include <string>
#include <vector>

namespace ns_search_backtracking_n_queens {

class Solution {
public:
    int countSolutions(int n) {
        int count = 0;
        std::vector<bool> col(n), diag1(2 * n), diag2(2 * n);
        std::vector<std::string> board(n, std::string(n, '.'));
        std::function<void(int)> dfs = [&](int row) {
            if (row == n) {
                count++;
                return;
            }
            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[row - c + n] || diag2[row + c])
                    continue;
                board[row][c] = 'Q';
                col[c] = diag1[row - c + n] = diag2[row + c] = true;
                dfs(row + 1);
                board[row][c] = '.';
                col[c] = diag1[row - c + n] = diag2[row + c] = false;
            }
        };
        dfs(0);
        return count;
    }

    std::vector<std::vector<std::string>> solve(int n) {
        std::vector<std::vector<std::string>> results;
        std::vector<bool> col(n), diag1(2 * n), diag2(2 * n);
        std::vector<std::string> board(n, std::string(n, '.'));
        std::function<void(int)> dfs = [&](int row) {
            if (row == n) {
                results.push_back(board);
                return;
            }
            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[row - c + n] || diag2[row + c])
                    continue;
                board[row][c] = 'Q';
                col[c] = diag1[row - c + n] = diag2[row + c] = true;
                dfs(row + 1);
                board[row][c] = '.';
                col[c] = diag1[row - c + n] = diag2[row + c] = false;
            }
        };
        dfs(0);
        return results;
    }
};

}  // namespace ns_search_backtracking_n_queens
