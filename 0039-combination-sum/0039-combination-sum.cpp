class Solution {
    void findCombinations(int index, int target, vector<int>& candidates,
                          vector<vector<int>>& ans, vector<int>& ds) {
        // Base Case
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // pick element
        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, ans,
                             ds);
            ds.pop_back();
        }

        // exclude element
        findCombinations(index + 1, target, candidates, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};