#pragma once
#include <vector>
#include <queue>
#include <stack>

namespace ns_search_tree_traversal {

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int v = 0) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> inorder(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while (curr) { stk.push(curr); curr = curr->left; }
            curr = stk.top(); stk.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }

    std::vector<int> preorder(TreeNode* root) {
        std::vector<int> res;
        if (!root) return res;
        std::stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            auto* node = stk.top(); stk.pop();
            res.push_back(node->val);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return res;
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = (int)q.size();
            std::vector<int> level;
            for (int i = 0; i < sz; i++) {
                auto* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

}  // namespace ns_search_tree_traversal
