#include<bits/stdc++.h>
//Recurssive
bool f(int ind, int target, vector<int> &arr){
	if(target== 0) return true;
	if (ind == 0) return target == arr[0];
	bool nottake = f(ind-1, target, arr);
	bool take = false;
	if(target >= arr[ind]){
		take = f(ind-1, target-arr[ind], arr);
	}
	return take || nottake;
} 
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i=0;i<n;i++) sum+=arr[i];
	if((sum)%2==1) return false;
	int k = sum/2;
	return f(n-1, k, arr);
}
//Memoization
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
	if(target== 0) return true;
	if (ind == 0) return target == arr[0];
	if(dp[ind][target] != -1)return dp[ind][target];
	bool nottake = f(ind-1, target, arr, dp);
	bool take = false;
	if(target >= arr[ind]){
		take = f(ind-1, target-arr[ind], arr, dp);
	}
	return dp[ind][target] = take || nottake;
} 
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i=0;i<n;i++) sum+=arr[i];
	if((sum)%2==1) return false;
	int k = sum/2;
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp);
}
//Tabulation
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i=0;i<n;i++) sum+=arr[i];
	if((sum)%2==1) return false;
	int k = sum/2;
	vector<vector<bool>> dp(n, vector<bool>(k+1, false));
	for(int i=0;i<n;i++) dp[i][0] = true;
	dp[0][arr[0]] = true;
	for(int ind = 1;ind<n;ind++){
		for(int target = 1;target <= k; target++){
			bool nottake = dp[ind-1][target];
			bool take = false;
			if(target >= arr[ind])
				take = dp[ind-1][target-arr[ind]];
			dp[ind][target] = take || nottake;
		}
	}
	return dp[n-1][k];
}
//Space Optimization
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i=0;i<n;i++) sum+=arr[i];
	if((sum)%2==1) return false;
	int k = sum/2;
	vector<bool> prev(k+1, false), curr(k+1, false);
	prev[0] = curr[0] = true;
	prev[arr[0]] = true;
	for(int ind = 1;ind<n;ind++){
		for(int target = 1;target <= k; target++){
			bool nottake = prev[target];
			bool take = false;
			if(target >= arr[ind])
				take = prev[target-arr[ind]];
			curr[target] = take || nottake;
		}
		prev = curr;
	}
	return prev[k];
}
