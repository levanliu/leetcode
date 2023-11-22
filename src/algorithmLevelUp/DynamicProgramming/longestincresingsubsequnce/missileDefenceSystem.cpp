// acwing 187
//  3 2 5 4 1，target:多少个上升or下降子序列
// 决策：是放到上升还是下降，无法优化，只能暴力搜索 dfs求最小步数（记忆一个全局最小值，不断更新）or（迭代加深）
#include <iostream>
using namespace std;

const int N = 55;
int n, ans;
int q[N];
int up[N], down[N];

void dfs(int u, int su, int sd)
{
    if (su + sd >= ans)
        return;
    if (u == n)
    {
        ans = su + sd;
        return;
    }
    // 情况一：将当前数放在上升子序列中
    int k = 0;
    while (k < su && up[k] >= q[u])
        k++;
    int t = up[k];
    up[k] = q[u];
    if (k < su)
        dfs(u + 1, su, sd);
    else
        dfs(u + 1, su + 1, sd);
    up[k] = t;

    // 情况二：将当前数放在下降子序列中
    k = 0;
    while (k < su && down[k] <= q[u])
        k++;
    t = down[k];
    down[k] = q[u];
    if (k < sd)
        dfs(u + 1, su, sd);
    else
        dfs(u + 1, su, sd + 1);
    down[k] = t;
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
            cin >> q[i];

        ans = n;
        dfs(0, 0, 0);
        cout << ans;
    }
}