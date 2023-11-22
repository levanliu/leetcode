//
// Created by le on 2022/12/20.
//

#ifndef MAIN_WEIGHTCENTERTREE_H
#define MAIN_WEIGHTCENTERTREE_H

// #include <iostream>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class weightCenterTree
{
private:
    static const int N = 100010, M = N * 2;
    // g n linkedlist head,
    // e node val
    // ne node next
    // idx;
    int h[N], e[N], ne[N], idx;

public:
    void add(int a, int b)
    {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    int weightCenterTreeMain()
    {
        memset(h, -1, sizeof h);
        add(1, 2);
        add(2, 3);
        add(1, 4);
        add(2, 4);
        add(3, 4);
        cout << "hello world!" << endl;
        return 0;
    }
};

#endif // MAIN_WEIGHTCENTERTREE_H
