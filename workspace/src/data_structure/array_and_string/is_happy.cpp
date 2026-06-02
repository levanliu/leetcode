#include <string>
#include <unordered_map>
namespace ns_data_structure_array_and_string_is_happy {

class Solution {
public:
    std::unordered_map<int, int> m;
    bool isHappy(int n) {
        if (n == 1)
            return true;
        if (m.count(n))
            return false;
        m[n]++;
        int res = 0;
        std::string nstrs = std::to_string(n);
        for (char nstr : nstrs) {
            res += (nstr - '0') * (nstr - '0');
        }
        return isHappy(res);
    }
};
}  // namespace ns_data_structure_array_and_string_is_happy
