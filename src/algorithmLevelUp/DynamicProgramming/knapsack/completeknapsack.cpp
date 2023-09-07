#include <iostream>
using namespace std;
const int N = 1010;
int f[N][N];
int v[N], w[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // 与01背包几乎一样，唯一的变化就是k。k * v[i] <= j;
            for (int k = 0; k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
        }
    }
    cout << f[n][m] << endl;
}

int spaceOptimization()
{
    const int N = 1010;
    int f[N];
    int n, m, v, w;
    cin >> n >> m;
    /**
     * f[i , j ] = max( f[i-1,j] , f[i-1,j-v]+w ,  f[i-1,j-2*v]+2*w , f[i-1,j-3*v]+3*w , .....)
       f[i , j-v]= max(            f[i-1,j-v]   ,  f[i-1,j-2*v] + w , f[i-1,j-3*v]+2*w , .....)
       2式加一个w，对比1式
       即可得
       f[i][j]   = max( f[i-1][j], f[i,j-v]+w , )
    */
   /**
    *
    01knapsack
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w;               // 边输入边处理
        for (int j = m; j >= v; j--) // 逆序处理，避免污染，到j==v提前停止。
            f[j] = max(f[j], f[j - v] + w);
    }
   */

    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w;
        for (int j = v; j <= m; j++)
        {
            f[j] = max(f[j], f[j - v] + w);
        }
    }
    cout << f[m] << endl;
}
