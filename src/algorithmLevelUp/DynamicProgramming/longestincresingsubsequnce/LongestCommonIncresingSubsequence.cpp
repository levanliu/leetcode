// acwing 272

// 2 2 1 3
// 2 1 2 3

/**
 * 集合属性
 * f[i][j]所有由第一个序列的前i个字母，第二个序列前j个字母构成的，且以a[i]==b[j]结尾的长度。
 *
 * 状态计算
 * 最长公共子序列，a[i]在公共上升子序列中
 * 【包含a[i]|不包含a[i]】 -> f[i-i][j]
 * 包含a[i] 可以划分k类 lcs模式 空
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
int n;
int a[N], b[N];
int f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
            {
                f[i][j] = max(f[i][j], 1);
                for (int k = 1; k < j; k++)
                {
                    if (b[k] < b[j])
                    {
                        f[i][j] = max(f[i][j], f[i][k] + 1);
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[n][i]);
    printf("%d\n", res);
    return 0;
}

int better()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], maxv);
            if (b[j] < a[i])
                maxv = max(maxv, f[i][j] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[n][i]);
    printf("%d\n", res);
    return 0;
}