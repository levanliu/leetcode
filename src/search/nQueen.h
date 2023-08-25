//
// Created by le on 2022/12/19/..
//

#ifndef MAIN_NQUEEN_H
#define MAIN_NQUEEN_H

#include "iostream"

using namespace std;

class nQueen
{
private:
    static const int N = 20;
    int n;
    char g[N][N];
    bool row[N], col[N], dg[N], udg[N];

public:
    void dfs(int u)
    {
        if (u == n)
        {
            for (int i = 0; i < n; i++)
                puts(g[i]);
            puts("");
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!col[i] && !dg[u + i] && !udg[n + u - i])
            {
                g[u][i] = 'Q';
                col[i] = dg[u + i] = udg[n + u - i] = true;
                dfs(u + 1);
                col[i] = dg[u + i] = udg[n + u - i] = false;
                g[u][i] = '.';
            }
        }
    }
    /**
     * double choose.
     */
    void dfs2(int x, int y, int s)
    {
        if (y == n)
            y = 0, x++;
        if (x == n)
        {
            if (s == n)
            {
                for (int i = 0; i < n; i++)
                    puts(g[i]);
                puts("");
            }
            return;
        }
        // not put
        dfs2(x, y + 1, s);
        // put queen
        if (!row[x] && !col[y] && !dg[x + y] && !udg[n + y - x])
        {
            g[x][y] = 'Q';
            row[x] = col[y] = dg[x + y] = udg[n + y - x] = true;
            dfs2(x, y + 1, s + 1);
            g[x][y] = '.';
        }
    }

    int nQueenMain()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                g[i][j] = '.';
            }
        }
        dfs(0);
        dfs2(0, 0, 0);
        return 0;
    }
};

#endif // MAIN_NQUEEN_H
