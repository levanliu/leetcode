/**
 * There are
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
i, jump to one of the following: Stone
i+1,i+2,…,i+K. Here, a cost of
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

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

const int N = 100005;
const int K = 105;

int h[N];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i + j < n)
                dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }
    cout << dp[n - 1] << endl;
}