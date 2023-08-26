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
    //Step3
    if(dp[n] != -1) return dp[n];
    //step2
    dp[n] = cost[n] + min(solvedp(cost,n-1,dp),solvedp(cost,n-2,dp));
    return dp[n];

}
int solvedpBottomUp(vector<int>& cost,int n){
    //Step1 : Creation of dp array
    vector<int> dp(n+1);
    //Step2 : base case
    dp[0] = cost[0];
    dp[1] = cost[1];
    //Step3 : 
    for(int i=2;i<n;i++){
        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}

    int minCostClimbingStairs(vector<int>& cost) {
        //
        // int n = cost.size();
        // int ans = min(solveRecursion(cost,n-1),solveRecursion(cost,n-2));
        // return ans;

        //
        // int n = cost.size();
        // vector<int> dp(n+1,-1);
        // int ans = min(solvedp(cost,n-1,dp),solvedp(cost,n-2,dp));
        // return ans;

        //
        int n = cost.size();
        return solvedpBottomUp(cost,n);

    }
};