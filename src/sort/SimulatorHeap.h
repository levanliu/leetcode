#ifndef ACWING_SIMULATORHEAP_H
#define ACWING_SIMULATORHEAP_H

/**  index = [1,2,3,....,size]
 * 1、插入一个数  heap[++size] = x; up(size);
 * 2、求集合中的最小值 heap[1]
 * 3、删除最小值 heap[1] = heap[size]; size--; down(1);
 * 4、删除任意一个元素 heap[k] = heap[size]; size--; down(k); up(k);
 * 5、修改任意一个元素 heap[k] = x; down(k); up(k);
 */
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class SimulatorHeap
{
private:
    static const int N = 100010;
    int n, m;
    int h[N], ph[N], hp[N], h_size;

public:
    void heap_swap(int a, int b)
    {
        swap(ph[hp[a]], ph[hp[b]]);
        swap(hp[a], hp[b]);
        swap(h[a], h[b]);
    }

    void down(int u)
    {
        int t = u;
        if (u * 2 <= h_size && h[u * 2] < h[t])
            t = u * 2;
        if (u * 2 + 1 <= h_size && h[u * 2 + 1] < h[t])
            t = u * 2 + 1;
        if (u != t)
        {
            heap_swap(u, t);
            down(t);
        }
    }

    void up(int u)
    {
        while (u / 2 && h[u] < h[u / 2])
        {
            heap_swap(u, u / 2);
            u >>= 1;
        }
    }

    int simulatorHeapMain()
    {
        unordered_map<string, int> u_map = {
            {"I", 1},
            {"PM", 2},
            {"DM", 3},
            {"D", 4},
            {"C", 5}};

        cin >> n;
        while (n--)
        {
            string op;
            cin >> op;
            int k, x;
            switch (u_map[op])
            {
            case 1:
                int x;
                cin >> x;
                ++m;
                ++h_size;
                ph[m] = h_size;
                hp[h_size] = m;
                h[h_size] = x;
                up(h_size);
                break;
            case 2:
                cout << h[1] << endl;
                break;
            case 3:
                heap_swap(1, h_size);
                h_size--;
                down(1);
                break;
            case 4:
                cin >> k;
                k = ph[k];
                heap_swap(k, h_size);
                h_size--;
                up(k);
                down(k);
                break;
            case 5:
                cin >> k >> x;
                k = ph[k];
                h[k] = x;
                up(k);
                down(k);
                break;
            }
        }
        return 0;
    }
};

#endif