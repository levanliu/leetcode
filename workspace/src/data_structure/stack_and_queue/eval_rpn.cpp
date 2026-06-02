#include <string>
#include <vector>
namespace ns_data_structure_stack_and_queue_eval_rpn {

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        int stk[10010];
        int top = -1;
        for (std::string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int val2 = stk[top--];
                int val1 = stk[top--];
                char opt = token[0];
                switch (opt) {
                    case '+':
                        stk[++top] = val1 + val2;
                        break;
                    case '-':
                        stk[++top] = val1 - val2;
                        break;
                    case '*':
                        stk[++top] = val1 * val2;
                        break;
                    case '/':
                        stk[++top] = val1 / val2;
                        break;
                }
            } else {
                stk[++top] = std::stoi(token);
            }
        }
        return stk[top];
    }
};
}  // namespace ns_data_structure_stack_and_queue_eval_rpn
