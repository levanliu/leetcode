#include <catch2/catch_test_macros.hpp>
#include "workspace/src/search/tree_traversal/tree_traversal.cpp"

static ns_search_tree_traversal::TreeNode* buildTestTree() {
    // Tree shape:  1 -> left:2, right:3; 2 -> left:4, right:5
    auto* root = new ns_search_tree_traversal::TreeNode(1);
    root->left = new ns_search_tree_traversal::TreeNode(2);
    root->right = new ns_search_tree_traversal::TreeNode(3);
    root->left->left = new ns_search_tree_traversal::TreeNode(4);
    root->left->right = new ns_search_tree_traversal::TreeNode(5);
    return root;
}

static void deleteTree(ns_search_tree_traversal::TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

TEST_CASE("TreeTraversal", "[search][tree_traversal]") {
    ns_search_tree_traversal::Solution tt;
    ns_search_tree_traversal::TreeNode* root = buildTestTree();

    SECTION("inorder: 4 2 5 1 3") {
        auto res = tt.inorder(root);
        REQUIRE(res == std::vector<int>{4, 2, 5, 1, 3});
    }

    SECTION("preorder: 1 2 4 5 3") {
        auto res = tt.preorder(root);
        REQUIRE(res == std::vector<int>{1, 2, 4, 5, 3});
    }

    SECTION("levelOrder") {
        auto res = tt.levelOrder(root);
        REQUIRE(res.size() == 3);
        REQUIRE(res[0] == std::vector<int>{1});
        REQUIRE(res[1] == std::vector<int>{2, 3});
        REQUIRE(res[2] == std::vector<int>{4, 5});
    }

    SECTION("empty tree") {
        REQUIRE(tt.inorder(nullptr).empty());
        REQUIRE(tt.preorder(nullptr).empty());
        REQUIRE(tt.levelOrder(nullptr).empty());
    }

    deleteTree(root);
}
