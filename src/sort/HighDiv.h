//
// Created by le on 2022/11/24.
//

#ifndef ACWING_HIGHDIV_H
#define ACWING_HIGHDIV_H

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class HighDiv {
public:
    vector<int> div(vector<int> &A, int b, int &r) {
        vector<int> res;
        for (int i = A.size() - 1; i >= 0; i--) {
            r = r * 10 + A[i];
            res.push_back(r / b);
            r %= b;
        }
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        return res;
    }
    int divMain() {
        string a;
        int b;
        cin >> a >> b;
        vector<int> A;
        for (int i = a.size() - 1; i >= 0; i--) {
            A.push_back(a[i] - '0');
        }
        int r;
        auto C = div(A, b, r);
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
        cout << endl << r;
        return 0;
    }

};


#endif //ACWING_HIGHDIV_H
