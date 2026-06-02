#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res = 0;
        for(int i=0;i<n;i++){
            res += (columnTitle[i]-'A'+1)*(int)pow(26,n-i-1);
        }
        return res;
    }
};