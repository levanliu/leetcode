//282 sone merge
/**
* f(i,j)  all methods merge from i to j
* divde by split line, k,k+1
* f(l,k) + f(k+1,r) + s(l,r)
* min
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 307;

int a[N], s[N];
int f[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }

    memset(f, 0x3f, sizeof f);
    // 区间 DP 枚举套路：长度+左端点 
    for (int len = 1; len <= n; len ++) { // len表示[i, j]的元素个数
        for (int i = 1; i + len - 1 <= n; i ++) {
            int j = i + len - 1; // 自动得到右端点
            if (len == 1) {
                f[i][j] = 0;  // 边界初始化
                continue;
            }

            for (int k = i; k <= j - 1; k ++) { // 必须满足k + 1 <= j
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << f[1][n] << endl;


    return 0;
}

