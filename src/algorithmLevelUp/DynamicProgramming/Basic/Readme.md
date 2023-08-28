#### Part1 Memoization
#### Part2 Tabulation

###### recursion recursive
```cpp
int fib(int n)
{
    if(n<=2) return 1;
    return fib(n-1)+fib(n-2);
}
```
###### dynamic programming
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 50;
int dp[N];
int main(){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    int n;
    cin >> n;
    cout << dp[n];
}
```

```cpp
    int a=0,b=1;
    int c;
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        c = a+b;
        a = b;
        b = c;
    }
```