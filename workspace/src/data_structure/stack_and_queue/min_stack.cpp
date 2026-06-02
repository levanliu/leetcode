#include <algorithm>
namespace ns_stack_min_stack {

class Solution {
private:
    static constexpr int N = 30010;
    int stack[N];
    int topPointer = -1;

public:
    Solution() { memset(stack, 0, sizeof stack); }

    void push(int val) { stack[++topPointer] = val; }

    void pop() { --topPointer; }

    int top() { return stack[topPointer]; }

    int getMin() {
        int minVal = INT_MAX;
        for (int index = 0; index <= topPointer; index++) {
            minVal = std::min(minVal, stack[index]);
        }
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new Solution();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
}  // namespace ns_stack_min_stack
