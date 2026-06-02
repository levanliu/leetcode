#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        return sortedArrayToBSTHelper(nums,0,nums.size()-1);
    }

    TreeNode* sortedArrayToBSTHelper(vector<int>& nums,int left,int right){
        if(left > right){
            return nullptr;
        }
        int mid = left+right >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums,left,mid-1);
        root->right = sortedArrayToBSTHelper(nums,mid+1,right);
        return root;
    }
};