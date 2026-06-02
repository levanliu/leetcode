#pragma once
#include <vector>
#include <queue>
#include <functional>
#include <utility>

class BFS {
public:
    // Shortest path in binary maze (0=open, 1=wall), -1 if unreachable
    int shortestPath(const std::vector<std::vector<int>>& grid) {
        int n = (int)grid.size(), m = n ? (int)grid[0].size() : 0;
        if (n == 0 || grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
        std::queue<std::pair<int,int>> q;
        q.push({0, 0});
        dist[0][0] = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m
                    && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist[n-1][m-1];
    }

    // Count connected components (cells with value 1)
    int countComponents(std::vector<std::vector<int>> grid) {
        int n = (int)grid.size(), m = n ? (int)grid[0].size() : 0;
        int count = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        auto bfs = [&](int sx, int sy) {
            std::queue<std::pair<int,int>> q;
            q.push({sx, sy});
            grid[sx][sy] = 0;
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 0;
                        q.push({nx, ny});
                    }
                }
            }
        };
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) { bfs(i, j); count++; }
        return count;
    }
};
