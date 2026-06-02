#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n <= 1)
        {
            return n;
        }
        int ans = 1;
        set<char> windows;
        for (int i = 0, j = 0; j < n; j++)
        {
            while (windows.count(s[j]))
            {
                windows.erase(s[i++]);
            }
            windows.insert(s[j]);
            ans = max(ans, (int)windows.size());
        }
        return ans;
    }
};