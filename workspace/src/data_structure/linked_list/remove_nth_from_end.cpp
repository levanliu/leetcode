#include "workspace/src/data_structure/linked_list/list_node.hpp"
namespace ns_data_structure_linked_list_remove_nth_from_end {

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /** n = 0   1 = n-1  i = n - i */

        if (head->next == nullptr)
            return nullptr;

        ListNode* p = head;

        ListNode* cur = head;
        ListNode* pre = head;
        while (n--) {
            p = p->next;
        }

        if (p == nullptr)
            return head->next;

        while (p != nullptr) {
            pre = cur;
            cur = cur->next;
            p = p->next;
        }

        pre->next = cur->next;

        return head;
    }
};
}  // namespace ns_data_structure_linked_list_remove_nth_from_end
