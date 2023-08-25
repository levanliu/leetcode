//
// Created by le on 2022/11/24.
//

#ifndef ACWING_REVERSEPAIRNUMBER_H
#define ACWING_REVERSEPAIRNUMBER_H

#include<iostream>

using namespace std;

class ReversePairNumber {
public:
    int n;
    const static int N=1e5+10;
    long long q[N],tmp[N];

    long long merge_sort(int l,int r){
        if(l>=r) return 0;

        int mid = l+r >> 1;
        long long res = merge_sort(l,mid) + merge_sort(mid+1,r);
        int k=0,i=l,j=mid+1;
        while(i<=mid && j <= r){
            if(q[i] <= q[j]) tmp[k++] = q[i++];
            else{
                tmp[k++] = q[j++];
                res += mid-i+1;
            }
        }
        while(i<=mid) tmp[k++] = q[i++];
        while(j<=r) tmp[k++] = q[j++];

        for(int i=l,j=0;i<=r;i++,j++) q[i] = tmp[j];
        return res;
    }

};


#endif //ACWING_REVERSEPAIRNUMBER_H
