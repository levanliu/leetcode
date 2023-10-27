#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

int tt(bool arr[], int n){
    int m = 0, temp = 0;
    for(int i = 0 ; i<n; ++i){
        if(arr[i]){
            temp++;
        }else{
            temp = 0;
        }
        m=max(temp, m);
    }
    return m;
}

void solve(){
    int n,m,q;cin >> n >> m >> q;
    multiset<int, greater<int>> t;
    bool arr[n][m];
    for(int i = 0 ; i<n; ++i){
        for(int j = 0 ; j<m; ++j){
            cin >> arr[i][j];
        }
    }
    int dp[n];
    for(int i = 0 ; i<n; ++i){
        dp[i] = tt(arr[i], m);
    }
    while(q--){
        int x,y;cin >> x >> y;
        x--,y--;
        arr[x][y] = !arr[x][y];
        dp[x] = tt(arr[x], m);
        cout << *max_element(dp, dp+n) << endl;
    }
}


int main(){ 
    int t=1; 
    // cin >> t; 
    while(t--){
        solve();
        cout << endl;
    }
}
