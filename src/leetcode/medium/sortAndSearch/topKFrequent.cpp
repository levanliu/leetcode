#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto num : nums) {
          m[num]++;
        }

        auto cmp = [](pair<int, int> x, pair<int, int> y) {
          return x.second < y.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
  pq(cmp);
        for (auto& kv : m) {
          pq.push(kv);
        }

        vector<int> res(k);
        for (int i = 0; i < k; i++) {
          auto kv = pq.top();
          pq.pop();
          res[i] = kv.first;
        }

        return res;
      }
    };