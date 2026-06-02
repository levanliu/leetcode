#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

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
        while(p != nullptr){
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};