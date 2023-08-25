#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    void dfs(string cur,int lsize,int rsize,int n){
        if(cur.size() == 2*n){
            res.push_back(cur);
            return ;
        }

        if(lsize<n){
            cur += "(";
            dfs(cur,lsize+1,rsize,n);
            cur.pop_back();
        }

        if(rsize<lsize){
            cur += ")";
            dfs(cur,lsize,rsize+1,n);
            cur.pop_back();
        }
            
    }
    vector<string> generateParenthesis(int n) {
        dfs("",0,0,n);
        return res;
    }
};