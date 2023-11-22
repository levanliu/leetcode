//acwing 1010
#include<iostream>
using namespace std;

//greedy algorithm
const int N = 10010;
int n;
int q[N],f[N];
int g[N]; //存储每个序列末尾的数，该数组是一个单调递增的序列。可证明贪心与最优解数目相同 反链定理
int main()
{
    while(cin >> q[n])n++;
    int res = 0;
    for(int i=n;i;i--){
        f[i] = 1;
        for(int j=n;j>i;j--){
            if(q[i] > q[j]){
                f[i] = max(f[i],f[j]+1);
            }
        }
        res = max(f[i],q[i]);
    }

    int cnt =0;
    for(int i=0;i<n;i++)
    {
        int k = 0;
        while(k<cnt && g[k] < q[i]) k++; //遍历g数组，查找目标序列处。
        g[k] = q[i]; //更新某个序列的末尾值,or k==cnt 放入新开序列之中
        if(k>=cnt) cnt++;//新开序列
    }
    cout << cnt << endl;

}