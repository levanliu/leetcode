#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        double i = x;
        for(;abs(x-i*i)>1e-6;){
            i = i - (i*i-x)/(2*i);
        }
        return (int)i;
    }
};