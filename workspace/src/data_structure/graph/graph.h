#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <functional>
#include <algorithm>

// Graph represented as adjacency list (0-indexed nodes).
using Graph = std::vector<std::vector<int>>;

// ---- Connected Components -----------------------------------------------

// Count connected components using union-find.  O(n + e * alpha(n))
inline int countComponents(int n, const std::vector<std::pair<int,int>>& edges) {
    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;
    std::function<int(int)> find = [&](int x) -> int {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    };
    int components = n;
    for (auto [u, v] : edges) {
        int pu = find(u), pv = find(v);
        if (pu != pv) { parent[pu] = pv; --components; }
    }
    return components;
}

// ---- Cycle Detection (directed graph) -----------------------------------

// Returns true if directed graph contains a cycle.  O(V + E)
inline bool hasCycleDirected(int n, const Graph& adj) {
    // 0=white, 1=gray (in-stack), 2=black (done)
    std::vector<int> color(n, 0);
    bool found = false;
    std::function<void(int)> dfs = [&](int u) {
        if (found) return;
        color[u] = 1;
        for (int v : adj[u]) {
            if (color[v] == 1) { found = true; return; }
            if (color[v] == 0) dfs(v);
        }
        color[u] = 2;
    };
    for (int i = 0; i < n && !found; ++i)
        if (color[i] == 0) dfs(i);
    return found;
}

// ---- Topological Sort (Kahn's BFS) -------------------------------------

// Returns topological order, or empty vector if cycle exists.  O(V + E)
inline std::vector<int> topoSort(int n, const Graph& adj) {
    std::vector<int> indegree(n, 0);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u]) ++indegree[v];
    std::queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indegree[i] == 0) q.push(i);
    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    return static_cast<int>(order.size()) == n ? order : std::vector<int>{};
}

// ---- BFS / DFS on Graph -------------------------------------------------

// BFS: returns visited order from src.  O(V + E)
inline std::vector<int> bfsOrder(int n, const Graph& adj, int src) {
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    std::queue<int> q;
    q.push(src); visited[src] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (!visited[v]) { visited[v] = true; q.push(v); }
    }
    return order;
}

// DFS: returns visited order from src (iterative).  O(V + E)
inline std::vector<int> dfsOrder(int n, const Graph& adj, int src) {
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    std::stack<int> stk;
    stk.push(src);
    while (!stk.empty()) {
        int u = stk.top(); stk.pop();
        if (visited[u]) continue;
        visited[u] = true;
        order.push_back(u);
        for (int v : adj[u])
            if (!visited[v]) stk.push(v);
    }
    return order;
}

// ---- Bipartite Check ----------------------------------------------------

// Returns true if graph is bipartite (2-colorable).  O(V + E)
inline bool isBipartite(int n, const Graph& adj) {
    std::vector<int> color(n, -1);
    for (int start = 0; start < n; ++start) {
        if (color[start] != -1) continue;
        std::queue<int> q;
        q.push(start); color[start] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) { color[v] = 1 - color[u]; q.push(v); }
                else if (color[v] == color[u]) return false;
            }
        }
    }
    return true;
}
