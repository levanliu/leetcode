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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (l1 != nullptr || l2 != nullptr)
        {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;

            int sum = (val1 + val2 + carry) % 10;

            if (head != nullptr)
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            else
            {
                head = tail = new ListNode(sum);
            }
            carry = (val1 + val2 + carry) / 10;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (carry)
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};