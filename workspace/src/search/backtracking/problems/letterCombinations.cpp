#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> res;
    map<char, string> m{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    void dfs(int u, string cur, string digits)
    {
        if (u == digits.size())
        {
            res.push_back(cur);
            return;
        }
        string curMap = m[digits[u]];
        for (int i = 0; i < curMap.size(); i++)
        {
            dfs(u + 1, cur + curMap[i], digits);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return res;
        dfs(0, "", digits);
        return res;
    }
};