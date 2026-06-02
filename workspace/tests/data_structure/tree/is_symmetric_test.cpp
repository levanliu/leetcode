#include "workspace/src/data_structure/tree/is_symmetric.cpp"
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

TEST_CASE("isSymmetric", "[data_structure][tree][is_symmetric]") {
    using namespace ns_data_structure_tree_is_symmetric;
    Solution sol;
    SECTION("symmetric") {
        auto root = makeTree({1, 2, 2, 3, 4, 4, 3});
        REQUIRE(sol.isSymmetric(root) == true);
    }
    SECTION("not symmetric") {
        auto root = makeTree({1, 2, 2, -1, 3, -1, 3});
        REQUIRE(sol.isSymmetric(root) == false);
    }
    SECTION("single") {
        auto root = new TreeNode(1);
        REQUIRE(sol.isSymmetric(root) == true);
    }
}
