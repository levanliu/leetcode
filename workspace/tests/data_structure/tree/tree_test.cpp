#include "workspace/src/data_structure/tree/tree.cpp"
#include <catch2/catch_test_macros.hpp>

static TreeNode* buildBST() {
    // BST: 4 -> left:2, right:6; 2->left:1,right:3; 6->left:5,right:7
    TreeNode* r = new TreeNode(4);
    r->left = new TreeNode(2);
    r->right = new TreeNode(6);
    r->left->left = new TreeNode(1);
    r->left->right = new TreeNode(3);
    r->right->left = new TreeNode(5);
    r->right->right = new TreeNode(7);
    return r;
}

static void freeTree(TreeNode* n) {
    if (!n)
        return;
    freeTree(n->left);
    freeTree(n->right);
    delete n;
}

TEST_CASE("maxDepth", "[tree]") {
    TreeNode* r = buildBST();
    REQUIRE(maxDepth(r) == 3);
    REQUIRE(maxDepth(nullptr) == 0);
    freeTree(r);
}

TEST_CASE("isSymmetric", "[tree]") {
    TreeNode* sym = new TreeNode(1);
    sym->left = new TreeNode(2);
    sym->right = new TreeNode(2);
    REQUIRE(isSymmetric(sym));
    sym->left->left = new TreeNode(3);
    REQUIRE_FALSE(isSymmetric(sym));
    freeTree(sym);
}

TEST_CASE("isValidBST", "[tree]") {
    TreeNode* r = buildBST();
    REQUIRE(isValidBST(r));
    r->left->right->val = 10;  // violate BST property
    REQUIRE_FALSE(isValidBST(r));
    freeTree(r);
}

TEST_CASE("insertBST and searchBST", "[tree]") {
    TreeNode* r = new TreeNode(5);
    r = insertBST(r, 3);
    r = insertBST(r, 7);
    r = insertBST(r, 4);
    REQUIRE(searchBST(r, 4) != nullptr);
    REQUIRE(searchBST(r, 6) == nullptr);
    freeTree(r);
}

TEST_CASE("sortedArrayToBST", "[tree]") {
    std::vector<int> v = {1, 2, 3, 4, 5};
    TreeNode* r = sortedArrayToBST(v);
    REQUIRE(isValidBST(r));
    REQUIRE(maxDepth(r) <= 3);
    freeTree(r);
}

TEST_CASE("lowestCommonAncestor", "[tree]") {
    TreeNode* r = buildBST();
    TreeNode* p = r->left->left;                        // 1
    TreeNode* q = r->left->right;                       // 3
    REQUIRE(lowestCommonAncestor(r, p, q) == r->left);  // LCA is 2
    freeTree(r);
}

TEST_CASE("serialize and deserialize", "[tree]") {
    TreeNode* r = buildBST();
    std::string s = serialize(r);
    TreeNode* r2 = deserialize(s);
    REQUIRE(serialize(r2) == s);
    freeTree(r);
    freeTree(r2);
}

TEST_CASE("hasPathSum", "[tree]") {
    TreeNode* r = buildBST();
    // Path 4->2->1 = 7
    REQUIRE(hasPathSum(r, 7));
    REQUIRE_FALSE(hasPathSum(r, 100));
    freeTree(r);
}
