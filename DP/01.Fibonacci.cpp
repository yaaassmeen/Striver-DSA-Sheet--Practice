class Solution {
    int solve(int n, vector<int> &dp){
        if(n<=1)return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
public:
    int fib(int n) {
        //Recursive
        // if(n<=0) return 0;
        // if(n==1) return 1;
        // return fib(n-1) + fib(n-2);

        //Memoization
        vector<int> dp(n+1, -1);
        return solve(n, dp);

        //Tabulation
        // if(n<1) return n;
        // int prev = 1;
        // int prev2 = 0;
        // for(int i=2;i<=n;i++){
        //     int cur1 = prev + prev2;
        //     prev2 = prev;
        //     prev = cur1;
        // }
        
        // return prev;

    }
};
