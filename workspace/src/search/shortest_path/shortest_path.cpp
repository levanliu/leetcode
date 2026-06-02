#include <climits>
#include <queue>
#include <utility>
#include <vector>

// Dijkstra's shortest path algorithm (heap-based, O((V+E) log V)).
// Works on non-negative weighted directed/undirected graphs.
// Graph is represented as adjacency list: adj[u] = {(v, w), ...}
namespace ns_search_shortest_path {

class Solution {
public:
    using Edge = std::pair<int, int>;  // {neighbor, weight}
    using Graph = std::vector<std::vector<Edge>>;

    // Returns shortest distances from src to every node (0-indexed).
    // dist[i] == INT_MAX means i is unreachable.
    std::vector<int> shortestPath(int n, const Graph& adj, int src) {
        std::vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // min-heap: {distance, node}
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

}  // namespace ns_search_shortest_path
