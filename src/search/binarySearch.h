#ifndef MAIN_BINARYSEARCH_H
#define MAIN_BINARTSEARCH_H

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> alls{1, 7, 8, 9, 10, 11};
int find_1(int x)
{
    int l = 0;
    int r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int find_2(int x)
{
    int l = 0;
    int r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (alls[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

const int N = 1000010;
int n, m, x;
int a[N], b[N];
int singleFind()
{
    scanf("%d%d%d", &n, &m, &x);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (size_t i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (i >= 0 && a[i] + b[j] > x)
            j--;
        if (a[i] + b[j] == x)
        {
            printf("%d %d\n", i, j);
            break;
        }
    }
    return 0;
}
#endif