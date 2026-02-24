class Solution {
    typedef pair<int, pair<int, int>> ppi;

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<ppi> pq;
        vector<vector<int>> ans;

        for (int i = 0; i < points.size(); i++) {
            int distance =
                (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);

            pq.push({distance, {points[i][0], points[i][1]}});

            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (pq.size() > 0) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};