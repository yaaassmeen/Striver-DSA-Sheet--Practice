class Solution {
    int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
        //base case
        if(ind ==0){
            if(amount%coins[ind] == 0) return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notpick = f(ind-1, amount, coins, dp);
        int pick = 1e9;
        if(coins[ind] <=amount) pick = 1 +f(ind, amount-coins[ind], coins, dp);
        return dp[ind][amount]=min(pick, notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = f(coins.size()-1, amount, coins, dp);
        // if(ans != 1e9)return ans;
        // return -1;
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int i=0; i<=amount; i++){
            if(i%coins[0] == 0)  
                dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        for(int ind = 1;ind<n;ind++){
            for(int target = 0; target<=amount;target++){
                int notpick = dp[ind-1][target];
                int pick = 1e9;
                if(coins[ind] <=target) pick = 1 + dp[ind][target-coins[ind]];
                dp[ind][target]=min(pick, notpick);
            }
        }
        if(dp[n-1][amount] >= 1e9) return -1;
        return dp[n-1][amount];
    }
};
