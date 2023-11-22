// acwing 1012
#include <iostream>
using namespace std;
/**
 * build bridge numbers max;
 * ---------o---------o--------o--------------o-o-o-----o
 * -------------o----------o----------o-o---o--------o----o
 * 1.每一个北岸的城市只能连接一个南岸的友好城市
 * 2.所有桥之间不可以相交
 *
 * 目标：最多可以建多少桥
 *
 * solution：
 *  任何一个合法的建桥方式必然是一个上升子序列。
 *  自变量排序，然后求出因变量的最长上升子序列。
 */
typedef pair<int, int> PII;
const int N = 5010;
int n;
PII q[N];
int f[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    sort(q, q + n);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (q[i].second > q[j].second)
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}