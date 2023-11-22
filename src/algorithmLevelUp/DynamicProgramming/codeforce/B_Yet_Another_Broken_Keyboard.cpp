#include <iostream>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

void solve(){
    int n,k; cin >> n>> k;
    string s; cin >> s;
    bool avail[26]={0};
    while(k--){
        char c; cin >> c;
        avail[c-'a'] = 1;
    }
    ll dp[n]={0};
    vector<int> a;
    for(int i = 0; i<n; ++i){
        if(!i){
            if(avail[s[i]-'a']) dp[0] = 1;
            continue;
        }
        if(avail[s[i]-'a']) dp[i] = dp[i-1] + 1;
        else a.push_back(i);
    }
    a.push_back(n);
    ll ans = 0;
    for(auto i: a){
        ans += dp[i-1]*(dp[i-1]+1)/2;
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
