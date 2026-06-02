#include <map>
#include <string>
#include <vector>
namespace ns_search_backtracking_letter_combinations {

class Solution {
public:
    std::vector<std::string> res;
    std::map<char, std::string> m{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                  {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                  {'8', "tuv"}, {'9', "wxyz"}};
    void dfs(int u, std::string cur, std::string digits) {
        if (u == digits.size()) {
            res.push_back(cur);
            return;
        }
        std::string curMap = m[digits[u]];
        for (int i = 0; i < curMap.size(); i++) {
            dfs(u + 1, cur + curMap[i], digits);
        }
    }
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0)
            return res;
        dfs(0, "", digits);
        return res;
    }
};
}  // namespace ns_search_backtracking_letter_combinations
