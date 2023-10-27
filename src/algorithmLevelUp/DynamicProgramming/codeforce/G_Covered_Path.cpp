#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

void solve(){
    int v1,v2,t,d;cin >> v1 >> v2 >> t >> d;
    int dp[1001][t+1] ;
    for(int i = 0 ; i<1001; ++i){
        for(int j = 0 ; j<=t; ++j){
            dp[i][j] = -INF;
        }
    }
    dp[v1][1] = v1;
    for(int i = 2; i<=t; ++i){ 
        for(int j = 0; j<=1000; ++j){
            int temp = 0;
            for(int k = max(j-d,0); k<=min(j+d,1000); ++k){
                dp[j][i] = max(dp[j][i], dp[k][i-1] + j);
            }
            // dp[j][i] = temp + j;
            // cout << temp;
        }

    }
    cout << dp[v2][t];
}

int main(){ 
    int t=1; 
    // cin >> t; 
    while(t--){
        solve();
        cout << endl;
    }
}
