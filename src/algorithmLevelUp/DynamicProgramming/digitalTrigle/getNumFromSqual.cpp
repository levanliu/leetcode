#include <iostream>
using namespace std;

/**
 * acwing 1027 382
 *
 * f[i1,j1,i2,j2] refer ro [1,1,1,1] -> [i1,j1,i2,j2] max val;
 *
 * how to deal same squal can not be choose repeat.
 *
 * when i1+j1 == i2+j2, two path exists repeat.
 *
 * f[,i1,i2] -> [1,1][1,1] -> [i1,k-i1][i2,k-i2] max
 * k represents two way sum:x+y
 * 
 * 
 */

// k = i1+j1 = i2+j2

const int N = 12;
int w[N][N];
int f[2 * N][N][N];

int main()
{
    int n;
    cin >> n;
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c)
    {
        w[a][b] = c;
    }
    for (int k = 2; k <= n + n; k++)
    {
        for (int i1 = 1; i1 <= n; i1++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int t = w[i1][j1];
                    if (i1 != i2)
                        t += w[i2][j2];
                    int &x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }
        }
    }
    cout << f[n + n][n][n];

    return 0;
}