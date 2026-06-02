#pragma once
#include <queue>
#include <vector>
#include "workspace/src/data_structure/tree/tree_node.hpp"

namespace ns_data_structure_tree_level_order {

class Solution {
public:
    static std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            const int numSize = static_cast<int>(q.size());
            std::vector<int> levelRes;
            for (int i = 0; i < numSize; i++) {
                TreeNode* cur = q.front();
                q.pop();
                levelRes.push_back(cur->val);
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            res.push_back(levelRes);
        }
        return res;
    }
};
}  // namespace ns_data_structure_tree_level_order
