#pragma once
#include "workspace/src/data_structure/tree/tree_node.hpp"
namespace ns_data_structure_tree_is_symmetric {

class Solution {
public:
    bool isSymmetric(TreeNode* root) { return isSymmetricHelper(root, root); }

    bool isSymmetricHelper(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr)
            return root1 == root2;

        if (root1->val != root2->val)
            return false;

        return isSymmetricHelper(root1->left, root2->right) &&
               isSymmetricHelper(root2->left, root1->right);
    }
};
}  // namespace ns_data_structure_tree_is_symmetric
