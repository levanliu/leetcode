#include <iostream>
using namespace std;

class Solution {
public:
//根据数学公式得出结果：(count[25] - 1) * (n + 1) + maxCount
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        int hash[26];
        memset(hash,0,sizeof(hash));
        int maxSize = 0;
        //求出出现的最高次数
        for(char t:tasks){
            hash[t-'A']++;
            maxSize = max(maxSize,hash[t-'A']);
        }int maxCount = 0;
        //求出现最高次的次数
        for(int i=0;i<26;i++){
            if(hash[i]==maxSize)
                maxCount++;
        }
        int res = (maxSize-1)*(n+1)+maxCount;
        //一旦出现res小于数组长度，答案就为数组长度
        return res>=size?res:size;
    }
};