//
// Created by le on 25/11/2022.
//

#ifndef MAIN_TWOSUM_H
#define MAIN_TWOSUM_H

#include "iostream"
#include "vector"
#include "map"
#include "unordered_map"
using namespace std;

class TwoSum
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

#endif // MAIN_TWOSUM_H
