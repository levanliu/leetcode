#include "workspace/src/data_structure/tree/sorted_array_to_bst.cpp"
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <functional>
#include <vector>

TEST_CASE("sortedArrayToBST", "[data_structure][tree][sorted_array_to_bst]") {
    using namespace ns_data_structure_tree_sorted_array_to_bst;
    Solution sol;
    SECTION("5 elements") {
        std::vector<int> nums = {-10, -3, 0, 5, 9};
        auto root = sol.sortedArrayToBST(nums);
        REQUIRE(root != nullptr);
        // Height-balanced: depth <= ceil(log2(n)) + 1
        std::function<int(TreeNode*)> depth = [&](TreeNode* n) -> int {
            return n == nullptr ? 0
                                : 1 + std::max(depth(n->left), depth(n->right));
        };
        REQUIRE(depth(root) <= 3);
    }
    SECTION("single") {
        std::vector<int> nums = {0};
        auto root = sol.sortedArrayToBST(nums);
        REQUIRE(root->val == 0);
    }
}
