#include <algorithm>
#include <vector>
namespace ns_skills_string_algorithm_reverse_string {

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (std::size_t i = 0; i < s.size() / 2; i++) {
            std::swap(s[i], s[s.size() - i - 1]);
        }
    }
};
}  // namespace ns_skills_string_algorithm_reverse_string
