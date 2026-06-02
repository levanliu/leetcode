#include <vector>
namespace ns_data_structure_array_and_string_count_primes {

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        std::vector<bool> flag(n, true);
        for (int i = 2; i < n; i++) {
            for (int j = 2; j * i < n; j++) {
                if (flag[i]) {
                    flag[i * j] = false;
                }
            }
        }
        int res = 0;
        for (int i = 2; i < n; i++) {
            res += flag[i];
        }
        return res;
    }
};
}  // namespace ns_data_structure_array_and_string_count_primes
