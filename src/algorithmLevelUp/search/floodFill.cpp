#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  const int dx[4] = {1, 0, 0, -1};
  const int dy[4] = {0, 1, -1, 0};
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    int curColor = image[sr][sc];
    if (image[sr][sc] == newColor) {
      return image;
    }

    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;

      image[x][y] = newColor;
      q.pop();
      int m = image.size();
      int n = image[0].size();
      for (int i = 0; i < 4; i++) {
        int xdx = x + dx[i];
        int ydy = y + dy[i];
        if (xdx >= 0 && xdx < m && ydy >= 0 && ydy < n &&
            image[xdx][ydy] == curColor) {
          q.push({xdx, ydy});
        }
      }
    }
    return image;
  }
};
