#include <iostream>
using namespace std;
class Solution
{
public:
    bool isValidSoduku(vector<vector<char>> &board)
    {
        int m = board.size();

        // row col cell  indicate the i row, j col, k cell has val?
        int row[m][m];
        int col[m][m];
        int cell[m][m];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int val = board[i][j] - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][val] != 0 || col[j][val] != 0 || cell[k][val] != 0)
                {
                    return false;
                }
                row[i][val] = col[j][val] = cell[k][val] = 1;
            }
        }
        return true;
    }
};
