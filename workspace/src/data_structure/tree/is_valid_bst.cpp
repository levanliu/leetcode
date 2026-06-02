#pragma once
#include "workspace/src/data_structure/tree/tree_node.hpp"
namespace ns_data_structure_tree_is_valid_bst {

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTHelper(TreeNode* root, long low, long high) {
        if (root == nullptr)
            return true;
        if (root->val <= low || root->val >= high)
            return false;
        return isValidBSTHelper(root->left, low, root->val) &&
               isValidBSTHelper(root->right, root->val, high);
    }
};
}  // namespace ns_data_structure_tree_is_valid_bst
