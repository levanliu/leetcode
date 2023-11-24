/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of
N days. For each
i (
1≤i≤N), Taro will choose one of the following activities and do it on the
i-th day:

A: Swim in the sea. Gain
a
i
​
  points of happiness.
B: Catch bugs in the mountains. Gain
b
i
​
  points of happiness.
C: Do homework at home. Gain
c
i
​
  points of happiness.
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

int dp[N][3];

void clmax(int &a, const int &b)
{
    if (a < b)
    {
        a = b;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ;
    int n;
    cin >> n;
    int a, b, c;
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        clmax(dp[i][0], max(dp[i - 1][1] + b, dp[i - 1][2] + c));
        clmax(dp[i][1], max(dp[i - 1][0] + a, dp[i - 1][2] + c));
        clmax(dp[i][2], max(dp[i - 1][0] + a, dp[i - 1][1] + b));
    }
    cout<<  max(dp[n][0], max(dp[n][1], dp[n][2]));
}