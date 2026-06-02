#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>
namespace ns_data_structure_hash_map_set_group_anagrams {

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> m;
        std::vector<std::vector<std::string>> res;
        for (auto str : strs) {
            std::string temp = str;
            std::sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }
        for (auto [k, v] : m) {
            res.push_back(v);
        }
        return res;
    }
};

}  // namespace ns_data_structure_hash_map_set_group_anagrams
