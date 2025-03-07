class Solution {
public:
    vector<vector<int>> bruteSol(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int start = a[i][0];
            int end = a[i][1];
            if (!ans.empty() && end <= ans.back()[1]) {
                // already lying inside the interval
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (a[j][0] <= end) {
                    // cheak if lying inside then update the upper bound
                    end = max(end, a[j][1]);
                } else // create new set
                    break;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
    vector<vector<int>> optimalSol(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (ans.empty() || a[i][0] > ans.back()[1]){
                // doesnt belong to existing interval
                ans.push_back(a[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], a[i][1]);
            }
        }
        return ans;
    }
    vector<vector<int>> merge(vector<vector<int>>& a) {
        return optimalSol(a);
    }
};