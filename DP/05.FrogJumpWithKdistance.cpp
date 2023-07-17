#include<bits/stdc++.h>
using namespace std;
//Recursive
// int solve(int ind, vector<int> &heights, int k){
//   if(int  == 0) return 0;
//   int minSteps = INT_MAX;
//   for(int j = 1;j<=k;j++){
//     if(ind-j >=0){
//       int a = solve(ind-j, heights, k) + abs(heights[ind] - heights[ind-j]);
//       minSteps=min(minSteps,a);
//     }
//   }
//   return minSteps;
// }
// int frogJump(int n, vector<int> &heights, int k){
//   return solve(n-1, heights, k);
// }
//Memoization
// int solve(int ind, vector<int> &heights, int k, vector<int> &dp){
//   if(int  == 0) return 0;
//   int minSteps = INT_MAX;
//   for(int j = 1;j<=k;j++){
//     if(ind-j >=0){
//       if(dp[ind-j] != -1) minSteps=min(minSteps,dp[ind-j]);
//       else{
//       int a = solve(ind-j, heights, k) + abs(heights[ind] - heights[ind-j]);
//       minSteps=min(minSteps,a);
//       }
//     }
//   }
//   return minSteps;
// }
// int frogJump(int n, vector<int> &heights, int k){
//   vector<int> dp(n, -1);
//   return solve(n-1, heights, k, dp);
// }
//Tabulation
int frogJump(int n, vector<int> &heights, int k){
  vector<int> dp(n, -1);
  dp[0] = 0;
  for(int i=1;i<n;i++){
    int minSteps = INT_MAX;
    for(int j = 1;j<=k;j++){
      int jump = INT_MAX;
      if(i-j >=0) jump = dp[i-j] + abs(heights[i] - heights[i-j]);
      minSteps = min(minSteps, jump);
    }
    dp[i] = minSteps;
  }
  return dp[n-1];
}
