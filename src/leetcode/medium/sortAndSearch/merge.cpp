#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for(auto interval:intervals){
            pair<int,int> temp;
            temp.first = interval[0];
            temp.second = interval[1];
            pq.push(temp);
        }

        vector<vector<int>> res;
        while(pq.size() >= 2){
            pair<int,int> cur = pq.top();
            pq.pop();
            pair<int,int> ne = pq.top();

            if(cur.second >= ne.first){
                pq.pop();
                pair<int,int> temp;
                temp.first = cur.first;
                temp.second = ne.second;
                if(cur.second >= ne.second)
                    temp.second = cur.second;
                pq.push(temp);
            }else{
                vector<int> v{cur.first,cur.second};
                res.push_back(v);
            }
        }
        if(pq.size() == 1){
            pair<int,int> cur = pq.top();
            pq.pop();
            vector<int> v{cur.first,cur.second};
            res.push_back(v);
        }
        return res;
    }
};