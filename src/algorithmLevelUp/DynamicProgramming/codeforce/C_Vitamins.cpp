#include <iostream>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

ll ib(ll num)
{
   ll numOfBits = 4;
   return (((1 << numOfBits) - 1) ^ num);
}

void solve(){
    int n;cin >> n;
    ll dp[8];
    for(int i = 1; i<8; ++i){
        dp[i] = INF;
    }
    dp[0] = 0;
    for(int i = 0 ; i<n; ++i){
        ll rate; cin >> rate;
        string s;cin >> s;
        int temp = 0;
        for(auto j: s){temp = temp|(1<<(j-'A'));}
        // cout << temp << endl;
        // cout << ib(temp) << endl;
        for(int j = 1; j<8 ; ++j){
            if(j&(temp)){
                ll x = ib(temp); 
                dp[j] = min(dp[j], rate + dp[j&x]);
            }
        }
    }
    if(dp[7] == INF) cout << -1;
    else cout << dp[7];
}

int main(){ 
    int t=1; 
    // cin >> t; 
    while(t--){
        solve();
        cout << endl;
    }
}
