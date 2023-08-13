#include<iostream>
using namespace std;
//Recurssive
int f(int ind, vector<int> &arr){
  if(ind == 0)return arr[0];
  if(ind<0) return 0;
  int pick = arr[ind] + f(ind -2, arr);
  int notpick = f(ind-1, arr);
  return max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    return f(nums.size()-1, nums);
}
//Memoization
int f(int ind, vector<int> &arr, vector<int> &dp){
  if(dp[ind] != -1)return dp[ind];
  if(ind == 0)return arr[0];
  if(ind<0) return 0;
  
  int pick = arr[ind] + f(ind -2, arr, dp);
  int notpick = f(ind-1, arr, dp);
  return dp[ind] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size(), -1);
    return f(nums.size()-1, nums, dp);
}
//Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for(int i=1;i<nums.size();i++){
      int pick = nums[i];
      if(i>1){
        pick+=dp[i-2];
      }
      int notpick = dp[i-1];
      dp[i] = max(pick ,notpick);
    }
    return dp[nums.size() - 1];
}
