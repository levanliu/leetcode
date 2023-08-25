#ifndef MAIN_HASHTABLESIM_H
#define MAIN_HASHTABLESIM_H

#include <iostream>
#include <limits.h>
#include <cstring>

using namespace std;

class HashTableSim
{
private:
    static const int N = 1e5 + 3;
    int h[N], e[N], ne[N], idx;

public:
    void insert(int x)
    {
        int k = (x % N + N) % N;
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx++;
    }

    bool query(int x)
    {
        int k = (x % N + N) % N;
        for (int idx = h[k]; idx != -1; idx = ne[idx])
        {
            if (e[idx] == x)
            {
                return true;
            }
        }
        return false;
    }

    int hashTableSimMain()
    {
        int m;
        memset(h, -1, sizeof h);
        scanf("%d", &m);
        while (m--)
        {
            char op[2];
            int x;
            scanf("%s%d", op, &x);
            if (*op == 'I')
            {
                insert(x);
            }
            else
            {
                if (query(x))
                    puts("Yes");
                else
                    puts("No");
            }
        }
        return 0;
    }
};

#endif