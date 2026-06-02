// LeetCode 138 - Copy List with Random Pointer
// Difficulty: Medium | Category: Linked List
// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <unordered_map>
namespace ns_data_structure_linked_list_138_copy_list_with_random_pointer {

struct Node {
    int val;
    Node* next;
    Node* random;

    explicit Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution
{
public:
    std::unordered_map<Node*, Node*> cachedNode;

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
