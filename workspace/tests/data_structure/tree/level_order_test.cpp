#include "workspace/src/data_structure/tree/level_order.cpp"
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

TEST_CASE("levelOrder", "[data_structure][tree][level_order]") {
    using namespace ns_data_structure_tree_level_order;
    Solution sol;
    SECTION("basic tree") {
        auto root = makeTree({3, 9, 20, -1, -1, 15, 7});
        auto result = sol.levelOrder(root);
        REQUIRE(result.size() == 3);
        REQUIRE((result[0] == std::vector<int>{3}));
        REQUIRE((result[1] == std::vector<int>{9, 20}));
        REQUIRE((result[2] == std::vector<int>{15, 7}));
    }
    SECTION("null") {
        REQUIRE(sol.levelOrder(nullptr).empty());
    }
}
