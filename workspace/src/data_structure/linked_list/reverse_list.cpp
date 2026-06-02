#pragma once
#include "workspace/src/data_structure/linked_list/list_node.hpp"
namespace ns_data_structure_linked_list_reverse_list {

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        head = nullptr;
        ListNode* q;
        while (p != nullptr) {
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};
}  // namespace ns_data_structure_linked_list_reverse_list
