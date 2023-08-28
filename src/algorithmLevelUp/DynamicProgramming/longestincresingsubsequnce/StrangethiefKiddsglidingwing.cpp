#include <bits/stdc++.h>
using namespace std;

/**
 * root acwing 895
 * acwing 1017->1014(482)
 * 1012
 * 1016
 * 1010 <LIS and 贪心> -> 187(暴力搜索)
 * 272 <LIS+LCS>
 */

// 双向LIS问题
const int N = 110;
int n;
int a[N], f[N];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
        for (int i = n; i > 0; i--)
        {
            f[i] = 1;
            for (int j = n; j > i; j--)
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
        cout << res;
    }
    return 0;
}