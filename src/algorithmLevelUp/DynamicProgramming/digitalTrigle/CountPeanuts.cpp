#include <bits/stdc++.h>
using namespace std;

/**
 * acwing 1015
 * dp f[i,j]
 * 1 state： all [1,1] -> [i,j];  dcipline : No repeat,No leak.
 *   propety Max/Min/Count
 *
 * 2 state compute   f[i,j] = { from up[f[i-1,j]+w[i,j]], from left[ f[i,j-1]+w[i,j] ]}
 */
const int N = 110;
int w[N][N];
int f[N][N];
int n, m;

class Solution
{
public:
    int CountPeanuts()
    {
        int T;
        scanf("%d", &T);
        while (T--)
        {
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    scanf("%d", &w[i][j]);
                }
            }

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    f[i][j] = max(f[i - 1][j], f[i][j - 1] + w[i][j]);
            printf("%d\n", f[n][m]);
        }
        return 0;
    }
};