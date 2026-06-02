#include <vector>
#include "workspace/src/data_structure/tree/tree_node.hpp"

namespace ns_data_structure_tree_sorted_array_to_bst {

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBSTHelper(std::vector<int>& nums, int left,
                                     int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, right);
        return root;
    }
};
}  // namespace ns_data_structure_tree_sorted_array_to_bst
