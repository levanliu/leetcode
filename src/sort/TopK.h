//
// Created by le on 6/11/2022.
//

#ifndef LANGUAGEBASIC_TOPK_H
#define LANGUAGEBASIC_TOPK_H

#include<iostream>

using namespace std;

class TopK {

/**
 * top M问题
 * 声明一个堆，堆容量为N  大根堆， 0 与 n-1 交换，调整堆
 *
 * 声明一个堆，大根堆容量为M， 当前值比M大 忽略，比M小 则与M进行交换。继续调整大根堆，
 * 0 - m-1
 *
 */
public:
    int n, m;
    static const int N = 10050;
    int q[N], h[N];

    void heapify(int h[], int i,int m) {
        int max = i;
        if (2 * i + 1 < m && h[2 * i + 1] > h[max]) {
            max = 2 * i + 1;
        }
        if (2 * i + 2 < m && h[2 * i + 2] > h[max]) {
            max = 2 * i + 2;
        }
        if (max != i) {
            swap(h[max], h[i]);
        }
    }

    void adjust_heap(int h[], int m) {
        for (int i = (m - 1) / 2; i >= 0; i--) {
            heapify(h, i,m);
        }
    }

    void build_heap(int q[], int h[]) {
        for (int i = 0; i < m; i++) {
            h[i] = q[i];
        }
        adjust_heap(h, m);

        for (int i = m; i < n; i++) {
            if (q[i] > h[0]) {
                continue;
            } else {
                h[0] = q[i];
                adjust_heap(h, m);
            }
        }
    }

    void heap_sort(int q[], int m) {
        build_heap(q, h);

        for (int i = m; i > 0; i--) {
            swap(h[0], h[i-1]);
            adjust_heap(h, i-1);
        }
    }


    void getTopK() {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }
        heap_sort(q, m);
        for (int i = 0; i < m; i++) {
            cout << h[i] << ' ';
        }
    }
};


#endif //LANGUAGEBASIC_TOPK_H
