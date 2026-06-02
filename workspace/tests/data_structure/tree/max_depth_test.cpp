#include "workspace/src/data_structure/tree/max_depth.cpp"
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

TEST_CASE("maxDepth", "[data_structure][tree][max_depth]") {
    using namespace ns_data_structure_tree_max_depth;
    Solution sol;
    REQUIRE(sol.maxDepth(makeTree({3, 9, 20, -1, -1, 15, 7})) == 3);
    REQUIRE(sol.maxDepth(makeTree({1, -1, 2})) == 2);
    REQUIRE(sol.maxDepth(nullptr) == 0);
}
