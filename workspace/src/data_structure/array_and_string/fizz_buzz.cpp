#include <string>
#include <vector>

namespace ns_data_structure_array_and_string_fizz_buzz {

class Solution {
public:
    static std::vector<std::string> fizzBuzz(int n) {
        constexpr int kFizz = 3;
        constexpr int kBuzz = 5;
        std::vector<std::string> res;
        for (int i = 1; i <= n; i++) {
            if (i % kFizz == 0 && i % kBuzz == 0) {
                res.push_back("FizzBuzz");
            } else if (i % kFizz == 0) {
                res.push_back("Fizz");
            } else if (i % kBuzz == 0) {
                res.push_back("Buzz");
            } else {
                res.push_back(std::to_string(i));
            }
        }
        return res;
    }
};
}  // namespace ns_data_structure_array_and_string_fizz_buzz
