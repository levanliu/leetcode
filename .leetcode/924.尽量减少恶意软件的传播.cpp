class Solution
{
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int n = graph.size();
        vector<int> ids(n);
        unordered_map<int, int> id_to_size; // very connected component id and size.
        int id = 0;
        for (int i = 0; i < n; ++i)
        {
            /**
             *  it means that the node has not been visited yet and does not belong to any group
             */
            if (!ids[i]) // check node i has already been assigned a group ID.
            {
                ++id;
                int size = 1;
                queue<int> q;
                q.push(i);
                ids[i] = id;
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for (int v = 0; v < n; ++v)
                    {
                        if (!ids[v] && graph[u][v] == 1)
                        {
                            ++size;
                            q.push(v);
                            ids[v] = id;
                        }
                    }
                }
                id_to_size[id] = size;
            }
        }
        /**
         *  the keys represent the group IDs
         *  the values represent the count of initial infected nodes in each group.
         *
         *  遍历所有的感染节点，并使用一个哈希表记录每个连通分量中感染节点的数目。
         */
        unordered_map<int, int> id_to_initials;
        for (int u : initial)
        {
            // mark initial group size.
            ++id_to_initials[ids[u]];
        }
        int ans = n + 1, ans_removed = 0;
        for (int u : initial)
        {
            // 我们计算出移除 u 可以减少的感染数removed
            // 如果 u所在的连通分量中有超过一个感染节点，那么值0,一个连通分量中多于一个的话，移除一个 剩下的仍然会感染连通分量的全部节点
            int removed = (id_to_initials[ids[u]] == 1 ? id_to_size[ids[u]] : 0);
            if (removed > ans_removed || (removed == ans_removed && u < ans))
            {
                ans = u;
                ans_removed = removed;
            }
        }
        return ans;
    }
};
