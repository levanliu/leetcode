#include<climits>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(divisor == -1) return (dividend == INT_MIN) ? INT_MAX : -1*dividend;
        if(divisor == INT_MIN) return (dividend == INT_MIN) ? 1 : 0;

        bool flag = ((dividend^divisor)&0x80000000) != 0;
        int c = 0;
        // convert to minus and calc
        if(divisor > 0) divisor = -1*divisor;
        if(dividend > 0) dividend = -1*dividend;
        while(dividend <= divisor) {
            int x = -divisor;
            int c1 = 1;
            while((x<<1) > 0 && -1*(x<<1) > dividend) {
                c1 += c1;
                x <<= 1;
            }
            c += c1;
            dividend += x;
        }
        return flag ? -1*c : c;
    }
};
