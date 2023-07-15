class Solution {
    // int solve(int n, vector<int> &dp){
    //     if(n<0) return 0;
    //     if(n==0 || n==1) return 1;
    //     if(n==2) return 2;
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = solve(n-1, dp) + solve(n-2,dp); 
    // }
public:
    int climbStairs(int n) {//dp
    //Recurssive
        // if(n<0) return 0;
        // if(n==0 || n==1) return 1;
        // if(n==2) return 2;
        // return climbStairs(n-1)+climbStairs(n-2);

        //Memoization
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        //Tabulation
        // vector<int> dp(n+1);
        // dp[0] = 1;
        // dp[1] = 1;
        // // dp[2] = 2;
        // for(int i=2;i<=n;i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

    //Tabulation Optimized


        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
    
        int prev = 2;
        int prev2 = 1;
        int ways = 0;
    
        for(int i=2; i<n; i++){
        	ways = prev + prev2;
        	prev2 = prev;
            prev = ways;
        }
        return ways;
    }
};
