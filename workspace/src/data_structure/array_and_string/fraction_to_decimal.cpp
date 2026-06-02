#include <string>
#include <unordered_map>
namespace ns_data_structure_array_and_string_fraction_to_decimal {

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        std::string ans = "";
        long x = numerator;
        long y = denominator;
        if (x % y == 0)
            return std::to_string(x / y);
        if ((x < 0) ^ (y < 0))
            ans += "-";
        x = std::abs(x);
        y = std::abs(y);
        ans = ans + std::to_string(x / y) + ".";
        x %= y;
        std::unordered_map<long, int> pos;
        while (x != 0) {
            pos[x] = ans.size();
            x *= 10;
            ans += std::to_string(x / y);
            x %= y;
            if (pos.count(x)) {
                ans.insert(pos[x], "(");
                ans += ")";
                break;
            }
        }
        return ans;
    }
};
}  // namespace ns_data_structure_array_and_string_fraction_to_decimal
