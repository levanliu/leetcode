#pragma once
#include <vector>
#include <queue>
#include <utility>

class TopologicalSort {
public:
    // Returns topological order, or empty if cycle detected
    std::vector<int> sort(int n, const std::vector<std::pair<int,int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        std::vector<int> indegree(n, 0);
        for (auto [u, v] : edges) { adj[u].push_back(v); indegree[v]++; }
        std::queue<int> q;
        for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);
        std::vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
        }
        return (int)order.size() == n ? order : std::vector<int>{};
    }

    bool hasCycle(int n, const std::vector<std::pair<int,int>>& edges) {
        return sort(n, edges).empty();
    }
};
