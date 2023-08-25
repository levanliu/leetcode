#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowbit(uint32_t n){
        return n&(-n);
    }
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            n -= lowbit(n);
            cnt++;
        }
        return cnt;
    }
};