#include<iostream>
using namespace std;

const int N = 25;
int f[N*N][2];
int dp[N];

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        cin >> f[i][0] >> f[i][1];
    }

    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            if( f[i][2] == k){
                dp[k] += 1;
            }
        }
        
    }

}