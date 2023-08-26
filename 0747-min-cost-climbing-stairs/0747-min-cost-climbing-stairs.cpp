class Solution {
public:
int solveRecursion(vector<int>& cost,int n){
    //Base
    if(n==0) return cost[0];
    if(n==1) return cost[1];

    int ans = cost[n] + min(solveRecursion(cost,n-1),solveRecursion(cost,n-2));
    return ans;

}

int solvedp(vector<int>& cost,int n,vector<int> &dp){
    //Base
    if(n==0) return cost[0];
    if(n==1) return cost[1];

    if(dp[n] != -1) return dp[n];

    dp[n] = cost[n] + min(solvedp(cost,n-1,dp),solvedp(cost,n-2,dp));
    return dp[n];

}

    int minCostClimbingStairs(vector<int>& cost) {
        //
        // int n = cost.size();
        // int ans = min(solveRecursion(cost,n-1),solveRecursion(cost,n-2));
        // return ans;

        //
        int n = cost.size();
        vector<int> dp(n+1,-1);
        int ans = min(solvedp(cost,n-1,dp),solvedp(cost,n-2,dp));
        return ans;
    }
};