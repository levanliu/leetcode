#pragma once
#include <vector>
#include <functional>

namespace ns_search_dfs {

class Solution {
public:
    // Flood fill: change all connected cells with same color
    void floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if (orig == color) return;
        int n = (int)image.size(), m = (int)image[0].size();
        std::function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != orig) return;
            image[x][y] = color;
            dfs(x+1, y); dfs(x-1, y); dfs(x, y+1); dfs(x, y-1);
        };
        dfs(sr, sc);
    }

    // Count distinct paths from top-left to bottom-right (only right/down moves, 0=open, 1=wall)
    int countPaths(const std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0][0] == 1) return 0;
        int n = (int)grid.size(), m = (int)grid[0].size();
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        int count = 0;
        std::function<void(int,int)> dfs = [&](int x, int y) {
            if (x == n-1 && y == m-1) { count++; return; }
            int dx[] = {0, 1};
            int dy[] = {1, 0};
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < n && ny < m && grid[nx][ny] == 0 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    dfs(nx, ny);
                    vis[nx][ny] = false;
                }
            }
        };
        vis[0][0] = true;
        dfs(0, 0);
        return count;
    }
};

}  // namespace ns_search_dfs
