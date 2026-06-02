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
    ListNode* reverseList(ListNode* head) {
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