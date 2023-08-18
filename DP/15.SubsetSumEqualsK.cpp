//Recurssive
#include <bits/stdc++.h> 
bool f(int ind, int target, vector<int> &arr){
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;
    bool nottake = f(ind-1,target, arr);
    bool take= false;
    if(target >= arr[ind])f(ind-1, target-arr[ind], arr);
    return take | nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.'
    return f(n-1, k, arr);
}
//Memoization
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;
    if(dp[ind][target] != -1) return dp[ind][target];
    bool nottake = f(ind-1,target, arr, dp);
    bool take= false;
    if(target >= arr[ind])f(ind-1, target-arr[ind], arr, dp);
    return dp[ind][target] = take | nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.'
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}
//Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}
