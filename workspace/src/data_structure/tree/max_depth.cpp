#include <algorithm>
#include "workspace/src/data_structure/tree/tree_node.hpp"

namespace ns_data_structure_tree_max_depth {

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0
                               : std::max(1 + maxDepth(root->left),
                                          1 + maxDepth(root->right));
    }
};

}  // namespace ns_data_structure_tree_max_depth
