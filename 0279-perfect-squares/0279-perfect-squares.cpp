class Solution {
public:
int SolveRec(int n){
    //Base Case
    if(n==0)    return 0;
    int ans = n;
    for(int i=1;i*i<=n;i++){
        ans = min(ans, 1 + SolveRec(n - (i*i) ) );
    }
    return ans;
}

int SolveMem(int n,vector<int> &dp){
    //Base Case
    if(n==0)    return 0;

    if(dp[n] != -1)     return dp[n];

    int ans = n;
    for(int i=1;i*i<=n;i++){
        ans = min(ans, 1 + SolveMem(n - (i*i),dp) );
    }
    dp[n] = ans;
    return ans;
}

    int numSquares(int n) {
        //
        // return SolveRec(n);

        //
        vector<int> dp(n+1,-1);
        return SolveMem(n,dp);
    }
};