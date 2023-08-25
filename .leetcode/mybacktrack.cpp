#include<bits/stdc++.h>
#include <vector>
using namespace std;

void backtrack(vector<int> arr,int target,int i,vector<int>& subset){
    if( target == 0 ){
        for(int s:subset){
            cout << s << " ";
        }
        cout << endl;
        return;
    }

    if(i == arr.size() ) return;

    backtrack(arr,target,i+1,subset);

    if(arr[i] <= target){
        subset.push_back(arr[i]);
        backtrack(arr,target-arr[i],i+1,subset);
        subset.pop_back();
    }
}


void sumK(vector<int> arr,int target){
    vector<int> subset;
    backtrack(arr,target,0,subset);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    int target;
    cin >> target;
    sumK(arr,target);
    return 0;
}

