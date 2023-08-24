#include<bits/stdc++.h>
//MEMOIZATION
int f(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector
<int>>& dp){    
    if (ind == 0) {
        return ((int)w/weight[0]) * profit[0];
    }
    if(dp[ind][w] != -1) return dp[ind][w];
    int notpick = f(ind-1, w, profit, weight, dp);
    int pick = INT_MIN;
    if(weight[ind] <= w) pick = profit[ind] + f(ind, w-weight[ind], profit, weight, dp);
    return dp[ind][w] = max(pick, notpick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return f(n-1, w, profit, weight, dp);
}
//TABULATION
int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){       
            int notTaken = 0 + dp[ind-1][cap];
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    return dp[n-1][W];
}
//SPACE OPTIMIZATION
int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    vector<int> cur(W+1,0);
    for(int i=wt[0]; i<=W; i++){
        cur[i] = ((int)i/wt[0]) * val[0];
    }
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            int notTaken = cur[cap];
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];           
            cur[cap] = max(notTaken, taken);
        }
    }
    return cur[W];
}
