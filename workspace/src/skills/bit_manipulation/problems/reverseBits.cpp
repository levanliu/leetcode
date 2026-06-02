#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            //res先往左移一位，把最后一个位置空出来，
            //用来存放n的最后一位数字
            res <<= 1;
            //res加上n的最后一位数字
            res |= n & 1;
            //n往右移一位，把最后一位数字去掉
            n >>= 1;
        }
        return res;
    }
};