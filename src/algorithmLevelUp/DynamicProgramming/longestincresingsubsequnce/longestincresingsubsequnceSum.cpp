// acwing 1016
#include <bits/stdc++.h>
using namespace std;

// f[1]...f[i-1] + a[i]

const int N = 1010;
int n;
int a[N], f[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i];
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + a[i]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res;
    return 0;
}