#include <algorithm>
#include "workspace/src/data_structure/linked_list/list_node.hpp"
namespace ns_data_structure_linked_list_is_palindrome {

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        //找到中点
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //如果fast不为空，说明链表的长度是奇数个
        if (fast != nullptr) {
            slow = slow->next;
        }
        //反转后半部分链表
        slow = reverse(slow);

        fast = head;
        while (slow != nullptr) {
            //然后比较，判断节点值是否相等
            if (fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
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
}  // namespace ns_data_structure_linked_list_is_palindrome
