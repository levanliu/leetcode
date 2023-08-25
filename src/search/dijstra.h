#ifndef MAIN_DIJSTRA_H
#define MAIN_DIJSTRA_H

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Dijstra
{
private:
    static const int N = 10010;

    int n, m;
    int g[N][N];
    int dist[N];
    bool st[N];

public:
    int dij(int g[N][N])
    {
        memset(dist, 0x3f, sizeof dist);
        int t = -1;
        for (int i = 0; i <= n - 2; i++)
        {
            for (int j = 1; j <= n - 1; j++)
            {
                if (!st[j] && (t == -1 || dist[t] > dist[j]))
                {
                    t = j;
                }
            }
        }

        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }

        if (dist[n] == 0x3f3f3f3f)
            return -1;
        return dist[n];
    }

    int dijstraMain()
    {
        memset(g, 0x3f, sizeof g);
        scanf("%d%d", &n, &m);
        int a, b, c;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            g[a][b] = min(g[a][b], c);
        }
        cout << dij(g);
        return 0;
    }
};
#endif