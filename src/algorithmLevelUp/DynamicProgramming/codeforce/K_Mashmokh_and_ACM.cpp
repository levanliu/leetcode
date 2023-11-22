#include <iostream>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

void solve(){
    ll n , k; cin >> n >> k;
    ll dp[k+1][n+1];
    memset(dp, 0 , sizeof(dp));

    dp[0][1] = 1;

    for(int i = 0 ; i<k; ++i){
        for(int j = 1 ; j<=n ; ++j){
            for(int k = j; k<=n; k+=j){
                dp[i+1][k] = (dp[i+1][k] + dp[i][j]) % 1000000007 ;
            }
        }
    }
    ll ans = 0; 
    for(int i = 1; i<=n; ++i){
        ans = (ans + dp[k][i])%1000000007 ;
    }
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
