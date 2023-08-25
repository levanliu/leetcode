#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int,int> m;
    bool isHappy(int n)
    {
        if(n==1) return true;
        if(m.count(n)) return false;
        m[n]++;
        int res = 0;
        string nstrs = to_string(n);
        for(char nstr:nstrs){
            res += (nstr-'0')*(nstr-'0');
        }
        return isHappy(res);
    }
};