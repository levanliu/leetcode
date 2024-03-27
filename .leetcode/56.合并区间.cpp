class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            int r = intervals[i][1];
            while (j < n && r >= intervals[j][0])
            {
                r = max(r, intervals[j][1]);
                j++;
            }
            res.push_back({intervals[i][0], r});
            i = j;
        }
        return res;
    }
};