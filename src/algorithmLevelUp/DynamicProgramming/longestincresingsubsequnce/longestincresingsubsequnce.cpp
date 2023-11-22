#include <iostream>
using namespace std;

/**
 * longest incresing subsequence
 * 划分依据，最后一个不同的点，划分成若干个集合。
 */

// 所有以a[i]结尾的严格单调上升子序列

// part1 状态表示 part2 状态计算

const int N = 10010;
int a[N];
int f[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }


    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res;
    return 0;
}