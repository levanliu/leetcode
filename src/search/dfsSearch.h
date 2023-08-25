//
// Created by le on 2022/12/19.
//

#ifndef MAIN_DFSSEARCH_H
#define MAIN_DFSSEARCH_H

#include "iostream"

using namespace std;

class dfsSearch {
private:
    static const int N = 10;
    int n;
    int path[N];
    bool st[N];

public:
    void dfs(int u) {
        if (u == n) {
            for (int i = 0; i < n; i++)
                printf("%d ", path[i]);
            puts("");
            return;
        }

        //第U个位置，可以放数字i
        for (int i = 0; i < n; i++) {
            if (!st[i]) {
                path[u] = i;
                st[i] = true;
                dfs(u + 1);
                st[i] = false;
            }
        }
    }

    int dfsMain() {
        cin >> n;
        dfs(0);
        return 0;
    }

};


#endif //MAIN_DFS_H
