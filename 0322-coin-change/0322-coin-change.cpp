class Solution {
public:
    int tabulation_1(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (ind == 0) {
            if ((amount % coins[0]) == 0) {
                return amount / coins[ind];
            } else
                return 1e9;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int notTake = 0 + tabulation_1(ind - 1, coins, amount, dp);
        int take = 1e9;
        if (coins[ind] <= amount)
            take = 1 + tabulation_1(ind, coins, amount - coins[ind], dp);

        return dp[ind][amount] = min(take, notTake);
    }
    int tabulation_2(vector<int>& coins, int amount){
        // Creating dp array of size amount+1
        vector<int> dp(amount + 1, INT_MAX);

        // Base case: dp[0] = 0
        dp[0] = 0;

        // Loop through all amounts from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Try each coin
            for (int coin : coins) {
                // If coin can be used
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    // Update dp[i] with minimum coins
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] is still infinity, return -1
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        /*
        int ans = tabulation_1(n - 1, coins, amount, dp);
        if (ans == 1e9) {
            return -1;
        }
        return ans;
        */

        return tabulation_2(coins, amount);
    }
};