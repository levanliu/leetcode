#include<iostream>
using namespace std;

class Solution {
public:
    int lowbit(int x){
        return x&(-x);
    }
    int hammingDistance(int x, int y) {
        int cnt = 0;
        int res = x^y;
        while(res){
            res -= lowbit(res);
            cnt++;
        }
        return cnt;
    }
};