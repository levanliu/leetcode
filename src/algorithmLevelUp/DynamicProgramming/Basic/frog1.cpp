/*
Problem Statement
There are
N stones, numbered
1,2,…,N. For each
i (
1≤i≤N), the height of Stone
i is
h
i
​
 .

There is a frog who is initially on Stone
1. He will repeat the following action some number of times to reach Stone
N:

If the frog is currently on Stone
i, jump to Stone
i+1 or Stone
i+2. Here, a cost of
∣h
i
​
 −h
j
​
 ∣ is incurred, where
j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone
N.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> h(n);

    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    // push dp
    for (int i = 0; i < n - 1; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        if (i + 2 < n)
        {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }
    cout << dp[n - 1];
}