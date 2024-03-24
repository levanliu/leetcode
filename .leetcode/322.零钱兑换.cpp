#include<bits/stdc++.h>

class Soultion
{
private:
    vector<int> count;
public:
    Soultion(/* args */);
    ~Soultion();
    int dp(vector<int> &coins, int rem);
    int coinChange(vector<int> &coins, int amount);
};

Soultion::Soultion(/* args */)
{
}

Soultion::~Soultion()
{
}

Solution::dp(vector<int> &coins,int rem){
    if(rem < 0)
        return -1;
    if(rem == 0)
        return 0;
    /**
     * 我们将每个子问题的答案存在一个数组中进行记忆化，如果下次还要计算这个问题的值直接从数组中取出返回即可，这样能保证每个子问题最多只被计算一次。
    */
    if(count[rem-1] != 0)
        return count[rem - 1];
    int Min = INT_MAX;
    for (int i = 0; i < coins.size();i++){
        int res = dp(coins, rem - coins[i]);
        if(res >= 0 && res < Min){
            Min = res + 1;
        }
    }
    count[rem - 1] = Min == INT_MAX ? -1 : Min;
    return count[rem - 1];
}

Solution::coinChange(vector<int> &coins,int amount){
    if(amount < 1)
        return 0;
    count.resize(amount);
    return dp(coins, amount);
}