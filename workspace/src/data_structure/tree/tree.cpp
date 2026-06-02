#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include "workspace/src/data_structure/tree/tree_node.hpp"

namespace ns_data_structure_tree {

class Solution {
public:
    // ---- Basic Properties -----------------------------------------------

    // Maximum depth (height) of a binary tree.  O(n)
    static int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }

    // Check if tree is symmetric (mirror of itself).  O(n)
    static bool isSymmetric(TreeNode* root) {
        std::function<bool(TreeNode*, TreeNode*)> mirror =
            [&](TreeNode* a, TreeNode* b) -> bool {
            if (!a && !b)
                return true;
            if (!a || !b || a->val != b->val)
                return false;
            return mirror(a->left, b->right) && mirror(a->right, b->left);
        };
        return !root || mirror(root->left, root->right);
    }

    // Path sum: does any root-to-leaf path sum to target?  O(n)
    static bool hasPathSum(TreeNode* root, int target) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return root->val == target;
        return hasPathSum(root->left, target - root->val) ||
               hasPathSum(root->right, target - root->val);
    }

    // Maximum path sum (any path, not just root-to-leaf).  O(n)
    static int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        std::function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node)
                return 0;
            int l = std::max(0, dfs(node->left));
            int r = std::max(0, dfs(node->right));
            result = std::max(result, node->val + l + r);
            return node->val + std::max(l, r);
        };
        dfs(root);
        return result;
    }

    // Diameter (longest path between any two nodes, measured in edges).  O(n)
    static int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        std::function<int(TreeNode*)> depth = [&](TreeNode* node) -> int {
            if (!node)
                return 0;
            int l = depth(node->left), r = depth(node->right);
            diameter = std::max(diameter, l + r);
            return 1 + std::max(l, r);
        };
        depth(root);
        return diameter;
    }

    // ---- BST Operations -------------------------------------------------

    // Validate BST.  O(n)
    static bool isValidBST(TreeNode* root, long long lo = LLONG_MIN,
                           long long hi = LLONG_MAX) {
        if (!root)
            return true;
        if (root->val <= lo || root->val >= hi)
            return false;
        return isValidBST(root->left, lo, root->val) &&
               isValidBST(root->right, root->val, hi);
    }

    // Search in BST.  O(h)
    static TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val)
            return root;
        return val < root->val ? searchBST(root->left, val)
                               : searchBST(root->right, val);
    }

    // Insert into BST.  O(h)
    static TreeNode* insertBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        if (val < root->val)
            root->left = insertBST(root->left, val);
        else
            root->right = insertBST(root->right, val);
        return root;
    }

    // Convert sorted array to height-balanced BST.  O(n)
    static TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
        return sortedArrayToBST(nums, 0, static_cast<int>(nums.size()) - 1);
    }

    // ---- Lowest Common Ancestor -----------------------------------------

    // LCA in binary tree (no BST guarantee).  O(n)
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,
                                          TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        auto* l = lowestCommonAncestor(root->left, p, q);
        auto* r = lowestCommonAncestor(root->right, p, q);
        if (l && r)
            return root;
        return l ? l : r;
    }

    // ---- Serialize / Deserialize ----------------------------------------

    // Level-order serialization: "1,2,3,null,null,4,5"
    static std::string serialize(TreeNode* root) {
        if (!root)
            return "";
        std::ostringstream out;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                out << node->val << ',';
                q.push(node->left);
                q.push(node->right);
            } else {
                out << "null,";
            }
        }
        std::string s = out.str();
        if (!s.empty())
            s.pop_back();  // remove trailing comma
        return s;
    }

    static TreeNode* deserialize(const std::string& data) {
        if (data.empty())
            return nullptr;
        std::istringstream in(data);
        std::string token;
        std::getline(in, token, ',');
        auto* root = new TreeNode(std::stoi(token));
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty() && std::getline(in, token, ',')) {
            TreeNode* node = q.front();
            q.pop();
            if (token != "null") {
                node->left = new TreeNode(std::stoi(token));
                q.push(node->left);
            }
            if (std::getline(in, token, ',') && token != "null") {
                node->right = new TreeNode(std::stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }

private:
    static TreeNode* sortedArrayToBST(const std::vector<int>& nums, int l,
                                      int r) {
        if (l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        auto* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, l, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, r);
        return node;
    }
};

}  // namespace ns_data_structure_tree
