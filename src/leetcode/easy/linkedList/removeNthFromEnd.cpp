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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /** n = 0   1 = n-1  i = n - i */

        if(head->next == nullptr )
            return nullptr;

        ListNode* p = head;
        
        ListNode* cur = head;
        ListNode* pre = head;
        while(n--){
            p = p->next;
        }

        if(p == nullptr)
            return head->next;

        while(p != nullptr){
            pre = cur;
            cur = cur->next;
            p = p->next;
        }

        pre->next = cur->next;

        return head;
    }
};