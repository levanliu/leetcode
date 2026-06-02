#include "workspace/src/data_structure/linked_list/list_node.hpp"
namespace ns_data_structure_linked_list_delete_node {

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
}  // namespace ns_data_structure_linked_list_delete_node
