class Solution {
    int f(int ind, int target, vector<int> &coins,vector<vector<int>> &dp){
        //Base case
        if(ind ==0){
            return target%coins[0] == 0;
        }
        if(dp[ind][target] !=-1) return dp[ind][target];
        int notpick = f(ind-1, target, coins, dp);
        int pick = 0;
        if(coins[ind] <= target){
            pick = f(ind, target-coins[ind],coins, dp);
        }
        return dp[ind][target] = pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        // return f(coins.size()-1, amount, coins, dp);
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Initializing base condition
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notTaken = dp[i - 1][j];

                int taken = 0;
                if (coins[i] <= j)
                    taken = dp[i][j - coins[i]];

                dp[i][j] = notTaken + taken;
            }
        }

        return dp[n - 1][amount];
    
    }
};
