#include "workspace/src/data_structure/tree/inorder_tracersal.cpp"
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

TEST_CASE("inorderTracersal", "[data_structure][tree][inorder]") {
    using namespace ns_data_structure_tree_inorder_tracersal;
    Solution sol;
    SECTION("BST") {
        auto root = makeTree({4, 2, 6, 1, 3, 5, 7});
        auto result = sol.inorderTracersal(root);
        REQUIRE((result == std::vector<int>{1, 2, 3, 4, 5, 6, 7}));
    }
    SECTION("null") {
        REQUIRE(sol.inorderTracersal(nullptr).empty());
    }
}
