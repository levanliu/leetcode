#include <iostream>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

void solve(){
    int n,k,p; cin >> n >> k >> p;
    int a[n+1], b[k+1];
    a[0] = 0,b[0] = 0;  
    for(int i = 1 ; i<=n; ++i){
        cin >> a[i];
    } 
    for(int i = 1 ; i<=k; ++i){
        cin >> b[i];
    }
    sort(a, a+sizeof(a) / sizeof(a[0]));
    sort(b, b+sizeof(b) / sizeof(b[0]));
    int dp[n][k];
    memset(dp,999999999,sizeof(dp));
    for(int i = 0 ; i<=k; ++i){
        dp[0][i] = 0;
    }
    for(int i = 1 ; i<=n; ++i){
        for(int j = i; j<=k; ++j){
            if(i==j){
                dp[i][j] = max(dp[i-1][j-1] , abs(b[j]-a[i]) + abs(p-b[j]));
            } 
            else dp[i][j] = min(dp[i][j-1], max(dp[i-1][j-1] , abs(b[j]-a[i]) + abs(p-b[j])));
        }
    }
    cout << dp[n][k];
}

int main(){ 
    int t=1; 
    // cin >> t; 
    while(t--){
        solve();
        cout << endl;
    }
}
