#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> PII;
    bool st[110][110];
    vector<int> res;
    void dfs(vector<vector<int>> &matrix, int x, int y, bool isDown)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || st[x][y])
            return;

        int dx[2] = {1, -1};
        int dy[2] = {1, -1};
        st[x][y] = true;
        res.push_back(matrix[x][y]);
        if (isDown)
        {
            dfs(matrix, x, y + dy[0], true);
            dfs(matrix, x + dx[0], y, true);
            dfs(matrix, x, y + dy[1], true);
            dfs(matrix, x + dx[1], y, false);
        }
        else
        {
            dfs(matrix, x + dx[1], y, false);
            dfs(matrix, x, y + dy[0], true);
        }
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        memset(st, 0, sizeof st);
        dfs(matrix, 0, 0, true);
        return res;
    }
};