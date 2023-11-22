#include <iostream>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> hash;
        int res = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                hash[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto it = hash.find(-(nums3[i] + nums4[j]));
                if (it != hash.end())
                {
                    res += it->second;
                }
            }
        }
        return res;
    }
};