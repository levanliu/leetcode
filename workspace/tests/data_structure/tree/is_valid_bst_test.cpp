#include "workspace/src/data_structure/tree/is_valid_bst.cpp"
#include <catch2/catch_test_macros.hpp>
#include <queue>
#include <vector>

static TreeNode* makeTree(std::vector<int> vals) {
    // BFS-style construction; -1 means null
    if (vals.empty()) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)vals.size()) {
        auto node = q.front(); q.pop();
        if (i < (int)vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        ++i;
        if (i < (int)vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

TEST_CASE("isValidBST", "[data_structure][tree][is_valid_bst]") {
    using namespace ns_data_structure_tree_is_valid_bst;
    Solution sol;
    SECTION("valid BST") {
        auto root = makeTree({2, 1, 3});
        REQUIRE(sol.isValidBST(root) == true);
    }
    SECTION("invalid BST") {
        auto root = makeTree({5, 1, 4, -1, -1, 3, 6});
        REQUIRE(sol.isValidBST(root) == false);
    }
    SECTION("single node") {
        auto root = new TreeNode(1);
        REQUIRE(sol.isValidBST(root) == true);
    }
}
