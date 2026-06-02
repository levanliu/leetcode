#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for (auto str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }
        for (auto [k, v] : m)
        {
            res.push_back(v);
        }
        return res;
    }
};
