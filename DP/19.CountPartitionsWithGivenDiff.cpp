const int MOD = 1e9 + 7;
//Memoization
#include <bits/stdc++.h> 
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    if(dp[ind][target] !=-1)return dp[ind][target];
    int notpick = f(ind-1, target, arr, dp);
    int pick = 0;
    if(arr[ind] <=target) pick = f(ind-1, target-arr[ind], arr, dp);
    return dp[ind][target]= pick + notpick;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = accumulate(arr.begin(),arr.end(), 0);
    int si = sum-d;
    if(si %2 == 1 || si <0) return 0;
    int s = (sum-d)/2;
    vector<vector<int>> dp(n, vector<int>(s+1, -1));
    return f(n-1, s, arr, dp);
}
//Tabulation
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = accumulate(arr.begin(),arr.end(), 0);
    int si = sum-d;
    if(si %2 == 1 || si <0) return 0;
    int s = (sum-d)/2;
    vector<vector<int>> dp(n, vector<int>(s + 1, 0));
    
    if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    
    if (arr[0] != 0 && arr[0] <= s) dp[0][arr[0]] = 1;
    
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= s; target++) {
            int notpick = dp[ind - 1][target];
            int pick = 0;

            if (arr[ind] <= target) {
              pick = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = (pick + notpick) % MOD;
        }
    }

    return dp[n - 1][s];
}
