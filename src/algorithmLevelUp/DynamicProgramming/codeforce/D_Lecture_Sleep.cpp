#include <iostream>
using namespace std; 
#define ll long long 
#define INF 0x3f3f3f3f
const int N = 200000 + 5;

void solve(){
    int n,k;cin >> n>> k;
    int a[n], t[n], x = 0;
    for(int i = 0 ; i<n; ++i){cin >> a[i];}
    for(int i = 0 ; i<n; ++i){cin >> t[i];}
    int dp[n][2];
    dp[0][1] = a[0];
    for(int i = 0 ; i<n; ++i){
        int temp = 0;
        if(t[i]==0)x+=a[i];
        else temp = a[i];
        if((i-k)>=0 && (t[i-k]==0)){x-=a[i-k];}   
        if(i){     
            dp[i][0] = dp[i-1][0]+temp;
            dp[i][1] = max(dp[i-1][1]+temp, dp[i-1][0]+x);
            // cout << x << " ";
        }else{
            dp[0][0] = temp;
            // cout << dp[0][0];
        }
    }
    // cout << dp[2][0];
    cout << max(dp[n-1][0], dp[n-1][1]);
}

int main(){ 
    int t=1; 
    // cin >> t; 
    while(t--){
        solve();
        cout << endl;
    }
}
