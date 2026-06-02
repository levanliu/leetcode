#pragma once
#include <stdexcept>
#include <vector>

namespace ns_data_structure_stack_and_queue {

template <typename T>
class Solution {
private:
    std::vector<T> data;

public:
    void push(const T& val) { data.push_back(val); }
    void pop() {
        if (empty())
            throw std::runtime_error("stack underflow");
        data.pop_back();
    }
    T& top() {
        if (empty())
            throw std::runtime_error("stack is empty");
        return data.back();
    }
    const T& top() const {
        if (empty())
            throw std::runtime_error("stack is empty");
        return data.back();
    }
    bool empty() const { return data.empty(); }
    std::size_t size() const { return data.size(); }
};

}  // namespace ns_data_structure_stack_and_queue
