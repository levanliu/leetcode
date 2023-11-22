#include <iostream>

using namespace std;

const int MAXN = 1005;
int v[MAXN];       // 体积
int w[MAXN];       // 价值
int f[MAXN][MAXN]; // f[i][j], j体积下前i个物品的最大价值

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
            if (j < v[i])
                f[i][j] = f[i - 1][j];
            // 能装，需进行决策是否选择第i个物品
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }

    cout << f[n][m] << endl;

    return 0;
}

/**
 * 状态f[j]定义：i件物品，背包容量j下的最优解。
 *
 */
int spaceOptimization()
{
    const int MAXN = 1005;
    int f[MAXN];
    int n, m, v, w;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w;               // 边输入边处理
        for (int j = m; j >= v; j--) // 逆序处理，避免污染，到j==v提前停止。
            f[j] = max(f[j], f[j - v] + w);
    }

    cout << f[m] << endl;

    return 0;
}