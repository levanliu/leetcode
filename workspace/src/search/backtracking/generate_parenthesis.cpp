#include <string>
#include <vector>
namespace ns_search_backtracking_generate_parenthesis {

class Solution {
public:
    std::vector<std::string> res;
    void dfs(std::string cur, int lsize, int rsize, int n) {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }

        if (lsize < n) {
            cur += "(";
            dfs(cur, lsize + 1, rsize, n);
            cur.pop_back();
        }

        if (rsize < lsize) {
            cur += ")";
            dfs(cur, lsize, rsize + 1, n);
            cur.pop_back();
        }
    }
    std::vector<std::string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return res;
    }
};
}  // namespace ns_search_backtracking_generate_parenthesis
