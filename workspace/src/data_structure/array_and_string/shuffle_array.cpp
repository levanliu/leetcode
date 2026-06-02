#include<iostream>
using namespace std;
namespace ns_data_structure_array_and_string_shuffle_array {


class Solution {
private:
    vector<int> res;
public:
    Solution(vector<int>& nums) {
        res = nums;
    }
    
    vector<int> reset() {
        return res;
    }
    
    vector<int> shuffle() {
        int n = res.size();
        vector<int> temp = res;
        for(int i=n;i;i--){
            int pos = rand()%i;
            swap(temp[pos],temp[i-1]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
} // namespace ns_data_structure_array_and_string_shuffle_array
