//
// Created by le on 2022/11/24.
//

#ifndef MAIN_KTHNUMBER_H
#define MAIN_KTHNUMBER_H
#include<iostream>

using namespace std;

class KthNumber {
public:
    int n,k;
    const static int N=1e6+10;
    int q[N];

    int quick_sort(int l,int r,int k){
        if(l>=r) return q[l];

        int x=q[l],i=l-1,j=r+1;
        while(i<j){
            while(q[++i] < x);
            while(q[--j] > x);
            if(i<j) swap(q[i],q[j]);
        }
        if(j>=k) return quick_sort(l,j,k);
        else return quick_sort(j+1,r,k);
    }
};


#endif //MAIN_KTHNUMBER_H
