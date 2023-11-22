#include <iostream>
using namespace std;
/**
 * 有N种物品和一个容量是V的背包。第i种物品最多有si件，每件体积是 vi，价值是 wi
 * 求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
 * 输出最大价值。
 *
 * f[i,j] = max(f[i-1,j],f[i-1,j-v]+w....f[i-1,j-sv]+sw)
 * f[i,j-v]  j-v是体积上限
 * f[i,j-2v]
 * f[i,j-3v]
 * ...
 * f[i,j-kv]
 * ...
 *
 *
 * -----------------------------------
 * f[i,j-kv]为 所有mod v同余 r  ,r +v ,r +2v,...,j-v,j
 *
 * 长度为s的窗口的最大值
 */

int a[10005], b[10005], t = 0, n, m, dp[10005] = {}, w, v, s;
int main()
{
    cin >> n >> m;
    while (n--)
    {
        cin >> v >> w >> s;
        while (s--)
        {
            a[++t] = v;
            b[t] = w;
        } // 死拆，把多重背包拆成01背包
    }
    for (int i = 1; i <= t; i++)
        for (int j = m; j >= a[i]; j--)
            dp[j] = max(dp[j - a[i]] + b[i], dp[j]); // 直接套01背包的板子
    cout << dp[m] << endl;
    return 0;
}

void simple()
{
    int dp[1005], n, t, v, w, s;
    memset(dp, 0, sizeof dp);
    cin >> n >> t;
    while (n--)
    {
        cin >> w >> v >> s;
        while (s--)
            for (int j = t; j >= w; j--)
                dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[t];
}