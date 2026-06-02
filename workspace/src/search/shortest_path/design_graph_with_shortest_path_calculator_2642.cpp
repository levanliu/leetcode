// LeetCode 2642 - Design Graph With Shortest Path Calculator
// Difficulty: Hard | Category: Shortest Path / Graph
// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/

#include <climits>
#include <queue>
#include <utility>
#include <vector>

typedef std::pair<int, int> PII;
namespace ns_shortest_path_design_graph {

class Solution {
private:
    std::vector<std::vector<PII>> graph;

public:
    Solution(int n, std::vector<std::vector<int>> edges) {
        graph.resize(n);
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            int cost = edge[2];
            graph[x].emplace_back(y, cost);
        }
    }
    void add(std::vector<int> edge) {
        int x = edge[0];
        int y = edge[1];
        int cost = edge[2];
        graph[x].emplace_back(y, cost);
    }

    int shortCost(int node1, int node2) {
        std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;
        std::vector<int> dist(graph.size(), INT_MAX);
        dist[node1] = 0;
        pq.emplace(0, node1);
        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();
            if (cur == node2) {
                return cost;
            }
            for (auto [next, ncost] : graph[cur]) {
                if (dist[next] > cost + ncost) {
                    dist[next] = cost + ncost;
                    pq.emplace(cost + ncost, next);
                }
            }
        }
        return -1;
    }
};

}  // namespace ns_shortest_path_design_graph
