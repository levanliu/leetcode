#include <string>
namespace ns_data_structure_array_and_string_title_to_number {

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int n = columnTitle.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (columnTitle[i] - 'A' + 1) * (int)pow(26, n - i - 1);
        }
        return res;
    }
};
}  // namespace ns_data_structure_array_and_string_title_to_number
