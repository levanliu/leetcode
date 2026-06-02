#include<iostream>
using namespace std;

class Solution {
    public:
       map<char,int> symbolValue ={{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    }};
    int romanToInt(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int val = 0;
            if (i < n - 1 && symbolValue[s[i]] < symbolValue[s[i+1]]) {
                val = -symbolValue[s[i]];
            } else {
                val = symbolValue[s[i]];
            }
            res += val;

        }
        return res;
    }
};