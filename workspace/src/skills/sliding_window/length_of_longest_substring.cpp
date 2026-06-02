#include <algorithm>
#include <set>
#include <string>
namespace ns_skills_sliding_window_length_of_longest_substring {

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size();
        if (n <= 1) {
            return n;
        }
        int ans = 1;
        std::set<char> windows;
        for (int i = 0, j = 0; j < n; j++) {
            while (windows.count(s[j])) {
                windows.erase(s[i++]);
            }
            windows.insert(s[j]);
            ans = std::max(ans, (int)windows.size());
        }
        return ans;
    }
};
}  // namespace ns_skills_sliding_window_length_of_longest_substring
