//
// Created by le on 4/1/2023.
//

#ifndef MAIN_VECTORSORT_H
#define MAIN_VECTORSORT_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class VectorSort
{
private:
    vector<vector<int>> a;

public:
    int vectorSortMain()
    {
        int n;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            a[i].push_back(x);
            a[i].push_back(y);
        }
        sort(a.begin(), a.end(), [](vector<int> &a, vector<int> &b)
             {
            if(a[0] != b[0]) return a[0] < b[0];
            else return a[1] > b[1]; });
        for (int i = 0; i < n; i++)
        {
            cout << a[i][0] << " " << a[i][1] << endl;
        }
        return 0;
    }
};

#endif // MAIN_VECTORSORT_H
