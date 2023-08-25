class Solution {
public:
   int topDownSolve(int n, vector<int>&dp) {
        // base case
        if(n == 1 || n == 2){
            return n;
        }
        // check answer already exists
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
    vector<int>dp(n+1, -1);
    int ans = topDownSolve(n, dp);
    return ans;
    }
};