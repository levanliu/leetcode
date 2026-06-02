// LeetCode 138 - Copy List with Random Pointer
// Difficulty: Medium | Category: Linked List
// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
struct Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>
namespace ns_data_structure_linked_list_138_copy_list_with_random_pointer {

class Solution
{
public:
    unordered_map<Node *, Node *> cachedNode;

    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (!cachedNode.count(head))
        {
            Node *headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};

} // namespace ns_data_structure_linked_list_138_copy_list_with_random_pointer
