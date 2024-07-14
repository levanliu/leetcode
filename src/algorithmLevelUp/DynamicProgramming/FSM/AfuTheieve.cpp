// f
// max(f[i-2] + w[i] , f[i-1])
//
// FSM
//
// 状态表示
// f(i,0),f(i,1)
//
// 集合：所有走了i步，且当前状态处于状态j的所有走法
//
// 属性：MAX
//
// 状态计算
//
// 0->0, 1->0
// f[i-1,0], f[i-1,1]
// 0->1 , f[i-1] = f[i-1,0] + w[i]
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int n;
int w[N], f[N][2];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
            scanf("%d", &w[i]);
        f[0][0] = 0, f[0][1] = -INF;
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + w[i];
        }
        printf("%d\n", max(f[n][0], f[n][1]));
    }
    return 0;
}
