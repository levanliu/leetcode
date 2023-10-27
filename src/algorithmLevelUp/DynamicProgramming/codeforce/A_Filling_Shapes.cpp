#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

void solve(){
    int n; cin >> n;
    ll dp[n+1];
    dp[0] = 0, dp[2] = 2;
    if(n%2){
        cout << 0;
        return;
    }else{
        for(int i = 4; i<=n; i+=2){
            dp[i] = 2*dp[i-2];
        }
        cout << dp[n];
        return;
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
