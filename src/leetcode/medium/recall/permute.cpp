#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    static const int N=7;
    int path[N];
    bool st[N];

    void dfs(int u,vector<int>& nums){
       
        if(u == nums.size()){
            vector<int> res(path,path+nums.size());
            ans.push_back(res);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!st[i]){
                path[u] = nums[i];
                st[i] = true;
                dfs(u+1,nums);
                st[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }
};