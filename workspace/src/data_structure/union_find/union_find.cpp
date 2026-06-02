#include <vector>

// Union-Find (Disjoint Set Union) with path compression.
// Supports merge and connected-query in near-O(1) amortized.
// Reference: AcWing 836
namespace ns_data_structure_union_find {

class Solution {
private:
    std::vector<int> parent;

public:
    explicit Solution(int n) : parent(n + 1) {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    // Find root with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Merge the sets containing a and b
    void unite(int a, int b) { parent[find(a)] = find(b); }

    // Returns true if a and b are in the same set
    bool connected(int a, int b) { return find(a) == find(b); }
};

}  // namespace ns_data_structure_union_find
