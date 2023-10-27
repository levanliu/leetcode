#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

ll ncr(ll n, ll r){
    ll ans = 1;
    for(int i = n-r+1; i<=n; ++i){
        ans *= i;
    }
    for(int i = 2; i<=r; ++i){
        ans /= i;
    }
    return ans;
}

void solve(){
    ll n, r, ans = 1;
    cin >> n >> r;
    if(r>=2) ans+= ncr(n,2);
    if(r>=3) ans+= ncr(n,3)*2;
    if(r>=4) ans+= ncr(n,4)*9;
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
