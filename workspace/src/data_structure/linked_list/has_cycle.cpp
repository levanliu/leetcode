#pragma once
#include "workspace/src/data_structure/linked_list/list_node.hpp"
namespace ns_data_structure_linked_list_has_cycle {

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
}  // namespace ns_data_structure_linked_list_has_cycle
