// acwing 1014

/**
 * 1:index must ++ ->subsequnence
 * 2:altitude not same;
 * 3:if increse not decrese.  2+3->先严格上升然后严格下降
 *
 * task:max count.
 *
 * 先求出双向LIS<从左往右+从右往左> 再把左右两边相加
 */
#include <iostream>
using namespace std;

const int N = 1010;
int n;
int a[N], f[N], g[N];
int main()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }
    for (int i = n; i > 0; i--)
    {
        g[i] = 1;
        for (int j = n; j > i; j--)
            if (a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i] + g[i] - 1);
    cout << res;
    return 0;
}