//
// Created by le on 2022/11/24.
//

#ifndef ACWING_NUMBERRANGE_H
#define ACWING_NUMBERRANGE_H
#include<iostream>

using namespace std;

class NumberRange {
public:
    int n,q,k;
    const static int N=1e5+10;
    int a[N];

    int* begin_end(int k){
        int* res = new int[2];
        int l=0,r=n-1;
        while(l<r){
            int mid = l+r >> 1;
            if(a[mid] >= k) r = mid;
            else l= mid+1;
        }
        if(a[l] != k){
            res[0] = -1;
            res[1] = -1;
        }else{
            res[0] = l;
            int l=0,r=n-1;
            while(l<r){
                int mid = l+r+1>> 1;
                if(a[mid] <= k) l = mid;
                else r= mid-1;
            }
            res[1] = r;
        }
        return res;
    }

};


#endif //ACWING_NUMBERRANGE_H
