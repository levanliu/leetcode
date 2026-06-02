#include <iostream>
namespace ns_skills_bit_manipulation_get_sum {

class Solution {
public:
    int add(int a, int b) {
        if (b == 0)
            return a;
        return add(a ^ b, (a & b) << 1);
    }
    int sub(int a, int b) { return add(a, add(~b, 1)); }
    int multiply(int a, int b) {
        int x = a >= 0 ? a : add((~a), 1);
        int y = b >= 0 ? b : add((~b), 1);
        int res = 0;
        while (y) {
            if (y & 1)
                res = add(res, x);
            x <<= 1;
            y >>= 1;
        }
        return (a ^ b) > 0 ? res : add(~res, 1);
    }
    int divide(int a, int b) {
        int x = a >= 0 ? a : add((~a), 1);
        int y = b >= 0 ? b : add((~b), 1);
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            if (x >> i >= y) {
                x = sub(x, y << i);
                res = add(res, 1 << i);
            }
        }
        int reminder = (a ^ b) > 0 ? x : add((~x), 1);
        std::cout << a << "/" << b << " reminder: " << reminder;
        return (a ^ b) > 0 ? res : add((~res), 1);
    }
};
}  // namespace ns_skills_bit_manipulation_get_sum
