#include<iostream>
using namespace std;

vector<vector<int>> res;
void sum(int target,vector<int>& vec,int u,vector<int>& tmp)
{
    if(target == 0){
        res.push_back(tmp);
        return;
    }
    if(u == vec.size()){
        return;
    }
    sum(target,vec,u+1,tmp);
    if(vec[u] <= target){
        tmp.push_back(vec[u]);
        sum(target-vec[u],vec,u+1,tmp);
        tmp.pop_back();
    }
}

int main()
{
    int target = 7;
    vector<int> vec{1,3,4,7,6,2,5};
    vector<int> tmp;
    sum(target,vec,0,tmp);
    for(auto r:res){
        for(auto val:r){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}