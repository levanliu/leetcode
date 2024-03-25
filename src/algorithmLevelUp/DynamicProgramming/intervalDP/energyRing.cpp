// 320 energy String.
// 状态表示，状态计算
// 集合 属性
// 所有将[l,r]合并成一个珠子的方式， 最大值
//[2,3][3,5][5,10][10,2]
// 2 3 5 10 2
// f[1,5] 一定是一个2*2的矩阵

/**
 * (l,k) (k,r) energy = (l,k,r)
 * f(l,k) f(k,r) w[l]*w[k]*w[r]
 */

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 210;

int n;
int w[N];
int f[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    w[i + n] = w[i];
  }

  for (int len = 3; len <= n + 1; len++) {
    for (int l = 1; l + len - 1 <= n * 2; l++) {
      int r = l + len - 1;
      for (int k = l + 1; k < r; k++) {
        f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, f[i][i + n]);
  }
  cout << res << endl;
  return 0;
}
