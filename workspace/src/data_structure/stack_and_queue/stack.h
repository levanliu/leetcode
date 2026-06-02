#pragma once
#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> data;
public:
    void push(const T& val) { data.push_back(val); }
    void pop() {
        if (empty()) throw std::runtime_error("stack underflow");
        data.pop_back();
    }
    T& top() {
        if (empty()) throw std::runtime_error("stack is empty");
        return data.back();
    }
    const T& top() const {
        if (empty()) throw std::runtime_error("stack is empty");
        return data.back();
    }
    bool empty() const { return data.empty(); }
    std::size_t size() const { return data.size(); }
};
