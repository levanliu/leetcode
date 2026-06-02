#include <array>
#include <string>
#include <vector>

// Trie (prefix tree): efficient string storage and prefix search.
// Supports insert and query-count operations.
// Reference: AcWing 835
namespace ns_data_structure_trie {

class Solution {
private:
    static const int N = 100010;
    // Heap-allocated to avoid large stack frames (~10 MB)
    std::vector<std::array<int, 26>> son;
    std::vector<int> cnt;
    int idx;

public:
    Solution() : son(N), cnt(N, 0), idx(0) {
        for (auto& arr : son)
            arr.fill(0);
    }

    // Insert a lowercase string into the trie
    void insert(const std::string& str) {
        int p = 0;
        for (char ch : str) {
            int u = ch - 'a';
            if (!son[p][u])
                son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }

    // Query how many times str has been inserted
    int query(const std::string& str) {
        int p = 0;
        for (char ch : str) {
            int u = ch - 'a';
            if (!son[p][u])
                return 0;
            p = son[p][u];
        }
        return cnt[p];
    }

    // Returns true if any inserted string starts with prefix
    bool startsWith(const std::string& prefix) {
        int p = 0;
        for (char ch : prefix) {
            int u = ch - 'a';
            if (!son[p][u])
                return false;
            p = son[p][u];
        }
        return true;
    }
};

}  // namespace ns_data_structure_trie
