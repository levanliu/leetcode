#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i=n;i>=5;i--){
            int k = i;
            while( k % 5 ==0){
                k/=5;
                res++;
            }
        }
        return res;
    }
};