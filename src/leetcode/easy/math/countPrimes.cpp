#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return 0;
        bool flag[n];
        memset(flag,1,sizeof flag);
        for(int i=2;i<n;i++){
            for(int j=2;j*i<n;j++){
                 if(flag[i]){
                     flag[i*j] = false;
                 }
            }
        }
        int res = 0;
        for(int i=2;i<n;i++){
            res += flag[i];
        }
        return res;
    }
};