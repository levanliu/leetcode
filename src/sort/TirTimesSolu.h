//
// Created by le on 2022/11/24.
//

#ifndef ACWING_TIRTIMESSOLU_H
#define ACWING_TIRTIMESSOLU_H

#include<iostream>
#include<cstdio>

using namespace std;
class TirTimesSolu {

public:
    double n;

    double tri(double n){
        double l=0,r=1000000;
        while(l+ (1e-7) <r){
            double mid = (l+r)/2;
            if(mid*mid*mid <= n) l=mid;
            else r=mid;
        }
        return l;
    }

};


#endif //ACWING_TIRTIMESSOLU_H
