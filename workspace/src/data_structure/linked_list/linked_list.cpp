#pragma once
#include <stdexcept>

namespace ns_data_structure_linked_list {

template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    explicit ListNode(T x) : val(x), next(nullptr) {}
};

template <typename T>
class Solution {
public:
    ListNode<T>* head = nullptr;

    void push_front(T val) {
        auto* node = new ListNode<T>(val);
        node->next = head;
        head = node;
    }

    T front() const {
        if (!head)
            throw std::runtime_error("empty list");
        return head->val;
    }

    void pop_front() {
        if (!head)
            return;
        ListNode<T>* tmp = head;
        head = head->next;
        delete tmp;
    }

    bool empty() const { return head == nullptr; }

    ~Solution() {
        while (head)
            pop_front();
    }
};

}  // namespace ns_data_structure_linked_list
