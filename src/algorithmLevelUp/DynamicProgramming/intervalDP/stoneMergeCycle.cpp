// 枚举缺口，时间复杂度n的四次方不可取
// 合并环形石子
// 复制一份，枚举2n中的n区间
// 迭代式，记忆化搜索的方式，
// 迭代长度，枚举左端点。
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 410, INF = 0x3f3f3f3f;
int n;
int s[N], w[N];
int f[N][N], g[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    w[i + n] = w[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    s[i] = s[i - 1] + w[i];
  }

  memset(f, 0x3f, sizeof f);
  memset(g, -0x3f, sizeof g);

  for (int len = 1; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n * 2; l++) {
      int r = l + len - 1;
      if (len == 1) {
        f[l][r] = g[l][r] = 0;
      } else {
        for (int k = l; k < r; k++) {
          f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]+ s[r] - s[r - 1]);
          g[l][r] = max(g[l][r], g[l][k] + f[k - 1][r]+ s[r] - s[l - 1]);
        }
      }
    }
  }

  int minv = INF, maxv = -INF;
  for (int i = 1; i <= n; i++) {
    minv = min(minv, f[i][i + n - 1]);
    maxv = max(maxv, g[i][i + n - 1]);
  }
  cout << minv << endl << maxv << endl;
  return 0;
}
