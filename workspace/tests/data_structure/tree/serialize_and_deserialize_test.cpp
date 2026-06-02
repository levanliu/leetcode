#include "workspace/src/data_structure/tree/serialize_and_deserialize.cpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("serializeDeserialize", "[data_structure][tree][serialize]") {
    using namespace ns_tree_serialize_deserialize;
    Solution sol;
    SECTION("basic round-trip") {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(5);
        std::string s = sol.serialize(root);
        TreeNode* restored = sol.deserialize(s);
        REQUIRE(restored->val == 1);
        REQUIRE(restored->left->val == 2);
        REQUIRE(restored->right->val == 3);
    }
    SECTION("null") {
        std::string s = sol.serialize(nullptr);
        TreeNode* restored = sol.deserialize(s);
        REQUIRE(restored == nullptr);
    }
}
