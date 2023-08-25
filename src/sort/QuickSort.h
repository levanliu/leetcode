//
// Created by le on 15/10/2022.
//

#ifndef CPP_QUICKSORT_H
#define CPP_QUICKSORT_H
#include "iostream"
#include "cstdio"
using namespace  std;

class QuickSort{
public:
    void quick_sort(int q[],int l,int r){
        if(l>=r) return;
        int x = q[l],i=l-1,j=r+1;
        while(i<j){
            do i++; while(q[i]<x);
            do j--; while(q[j]>x);
            if(i<j) swap(q[i],q[j]);
        }
        quick_sort(q,l,j);
        quick_sort(q,j+1,r);
    }
};


#endif
