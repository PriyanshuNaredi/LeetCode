class Solution {
public:
int solveRec(int n, vector<int>& days, vector<int> cost,int index){

    //Base Case
    if(index >= n)      return 0;
    // 1 Day Pass
    int option1 = cost[0] + solveRec(n, days, cost, index+1);

    // 7 Day PAss
    int i;
    for(i = index; i < n && days[i] < days[index] + 7; i++ );
    int option2 = cost[1] + solveRec(n, days, cost, i);

    // 30 Days Pass
    for(i = index; i < n && days[i] < days[index] + 30; i++ );
    int option3 = cost[2] + solveRec(n, days, cost, i);

    return min(option1,min(option2,option3));
}

int solveMemo(int n, vector<int>& days, vector<int> cost,int index,vector<int> &dp){

    //Base Case
    if(index >= n)      return 0;

    // Step3
    if(dp[index] != -1)     return dp[index];

    // 1 Day Pass
    int option1 = cost[0] + solveMemo(n, days, cost, index+1,dp);

    // 7 Day PAss
    int i;
    for(i = index; i < n && days[i] < days[index] + 7; i++ );
    int option2 = cost[1] + solveMemo(n, days, cost, i,dp);

    // 30 Days Pass
    for(i = index; i < n && days[i] < days[index] + 30; i++ );
    int option3 = cost[2] + solveMemo(n, days, cost, i,dp);

    dp[index] = min(option1,min(option2,option3));
    return dp[index];
}

int solveTab(int n, vector<int>& days, vector<int> cost){

    vector<int> dp(n+1,INT_MAX);

    //Base Case
    dp[n] = 0;

    for(int k = n-1;k>=0;k--){
        // 1 Day Pass
        int option1 = cost[0] + dp[k+1];

        // 7 Day PAss
        int i;
        for(i = k; i < n && days[i] < days[k] + 7; i++ );
        int option2 = cost[1] +dp[i];

        // 30 Days Pass
        for(i = k; i < n && days[i] < days[k] + 30; i++ );
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1,min(option2,option3));
    }

    return dp[0];

}

int solve(int n, vector<int> days, vector<int> cost){

    int ans =0;
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for(int day:days){
        //STEP 1 : REMOVE EXPIRED DAYS
        while(!month.empty() && month.front().first +30 <=day)
         month.pop();
        while(!week.empty() && week.front().first + 7 <=day)
         week.pop();

        //STEP 2: ADD COST FOR CURRENT DAY
        week.push(make_pair(day, ans+cost[1]));
        month.push(make_pair(day, ans+cost[2]));

        //STEP 3 : ANS UPDATE WHICH IS TO FIND MINIMUM COST
        ans = min(ans+cost[0] , min(week.front().second,month.front().second));

    }

    return ans;
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days.size(), days, costs);
    }
};