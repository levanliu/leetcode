#ifndef MAIN_DOUBLELINKEDLIST_H
#define MAIN_DOUBLELINKEDLIST_H

#include <iostream>
#include <cstring>
#include <map>
using namespace std;

class DoubleLinkedList
{
private:
    static const int N = 100010;
    int l[N], r[N], e[N], idx;

public:
    void add_r(int k, int x)
    {
        e[idx] = x;
        r[idx] = r[k];
        l[idx] = k;
        l[r[k]] = idx;
        r[k] = idx++;
    }

    void add_l(int k, int x)
    {
        add_r(l[k], x);
    }

    void del(int k)
    {
        r[l[k]] = r[k];
        l[r[k]] = l[k];
    }

    void doubleLinedListMain()
    {
        int M;
        cin >> M;
        r[0] = 1;
        l[0] = 0;
        idx = 2;
        map<string, int> opt_map = {
            {"L", 0},
            {"R", 1},
            {"D", 2},
            {"IR", 3},
            {"IL", 4}};
        while (M--)
        {
            string opt;
            cin >> opt;
            switch (opt_map[opt])
            {
            case 0:
            {
                int x;
                cin >> x;
                add_r(0, x);
                break;
            }
            case 1:
            {
                int x;
                cin >> x;
                add_l(1, x);
                break;
            }
            case 2:
            {
                int k;
                cin >> k;
                del(k + 1);
                break;
            }
            case 3:
            {
                int k, x;
                cin >> k >> x;
                add_r(k + 1, x);
                break;
            }
            case 4:
            {
                int k, x;
                cin >> k >> x;
                add_l(k + 1, x);
                break;
            }
            }
        }
        for (int i = r[0]; i != 1; i = r[i])
            cout << e[i] << ' ';
        cout << endl;
    }
};

#endif
