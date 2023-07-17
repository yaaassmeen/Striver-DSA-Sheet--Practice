#include<bits/stdc++.h>
using namespace std;

//Recursive
/*
int solve(int ind, vector<int> &heights){
  if(ind == 0)return 0;
  int left = solve(ind-1, heights) + abs(heights[ind] - heights[ind-1]);
  int right = INT_MAX;
  if(ind>1) right = solve(ind-2,heights) + abs(heights[ind] - heights[ind-2]);
  return min(left, right);
}
int frogJump(int n, vector<int> heights){
  return solve(n-1, heights);
}
*/
//Memoization
/*
int f(int ind, vector<int> &heights, vector<int> &dp){
  if(ind == 0)return 0;
  if(dp[ind]!=-1) return dp[ind];
  int left = solve(ind-1, heights) + abs(heights[ind] - heights[ind-1]);
  int right = INT_MAX;
  if(ind>1) right = solve(ind-2,heights) + abs(heights[ind] - heights[ind-2]);
  return min(left, right);
}
int frogJump(int n, vector<int> heights){
  vector<int> dp(n+1, -1);
  return f(n-1, heights, dp);
}*/
//Tabulation
/*int frogJump(int n, vector<int> heights{
  vector<int> dp(n,-1);
  dp[0] = 0;
  for(int i=1;i<n;i++){
    int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
    int ss = INT_MAX;
    if(i>1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);
    dp[i] = min(fs,ss);
  }
  return dp[n-1];
}*/
//Tabulation space optimized
int frogJump(int n, vector<int> heights{
  int prev2 = 0, prev = 0, curr = 0;
  for(int i=1;i<n;i++){
    int fs = prev + abs(heights[i] - heights[i-1]);
    int ss = INT_MAX;
    if(i>1) ss = prev2 + abs(heights[i] - heights[i-2]);
    curr = min(fs,ss);
    prev2 = prev;
    prev = curr;
  }
  return prev;
}
