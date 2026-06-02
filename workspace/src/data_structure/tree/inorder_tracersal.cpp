#pragma once
#include <utility>
#include <vector>
#include "workspace/src/data_structure/tree/tree_node.hpp"

namespace ns_data_structure_tree_inorder_tracersal {

class Solution {
public:
    std::vector<int> inorderTracersal(TreeNode* root) {
        typedef std::pair<int, TreeNode*> PII;
        std::vector<int> res;
        if (root == nullptr)
            return res;
        int n = 110;
        PII stk[n];
        int top = -1;
        stk[++top] = {0, root};
        while (top != -1) {
            PII cur = stk[top--];
            int color = cur.first;
            TreeNode* curNode = cur.second;
            if (color == 1) {
                res.push_back(curNode->val);
            } else {
                if (curNode->right != nullptr)
                    stk[++top] = {0, curNode->right};
                stk[++top] = {1, curNode};
                if (curNode->left != nullptr)
                    stk[++top] = {0, curNode->left};
            }
        }
        return res;
    }
};

}  // namespace ns_data_structure_tree_inorder_tracersal
