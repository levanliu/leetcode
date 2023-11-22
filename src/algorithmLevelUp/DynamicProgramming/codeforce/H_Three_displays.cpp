#include <iostream>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

void solve(){
    int n;cin >> n;
    ll s[n], c[n];
    for(int i = 0 ; i<n; ++i){
        cin >> s[i];
    } 
    for(int i = 0 ; i<n; ++i){
        cin >> c[i];
    }
    ll dp[n][4];
    for(int i = 0 ; i<n; ++i){
        for(int j = 0 ; j<=3; ++j){
            dp[i][j] = INF;
        }
    }
    for(int i = 0 ; i<n; ++i){
        dp[i][1] = c[i];
        for(int k = 2; k<=3; ++k){
            for(int j = 0 ; j<i; ++j){
                if(s[i]>s[j]){
                    dp[i][k] = min(dp[i][k], dp[j][k-1]+c[i]);
                }
            }
        }
    }
    ll ans = INF;
    for(int i = 0 ; i<n; ++i){
        ans = min(ans, dp[i][3]);
    }
    if(ans == INF) ans = -1;
    cout << ans;
}

int main(){ 
    int t=1; 
    // cin >> t; 
    while(t--){
        solve();
        cout << endl;
    }
}
