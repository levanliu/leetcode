#pragma once
#include "workspace/src/data_structure/linked_list/list_node.hpp"
namespace ns_data_structure_linked_list_add_two_numbers {

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (l1 != nullptr || l2 != nullptr) {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;

            int sum = (val1 + val2 + carry) % 10;

            if (head != nullptr) {
                tail->next = new ListNode(sum);
                tail = tail->next;
            } else {
                head = tail = new ListNode(sum);
            }
            carry = (val1 + val2 + carry) / 10;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (carry) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
}  // namespace ns_data_structure_linked_list_add_two_numbers
