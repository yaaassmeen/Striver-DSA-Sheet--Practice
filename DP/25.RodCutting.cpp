#include<bits/stdc++.h>
//MEMOIZATION
int f(int ind, int len, vector<int> &val, vector<vector<int>> &dp){
	if(ind == 0)return len*val[0];
	if(dp[ind][len] !=-1) return dp[ind][len];
	int notpick = f(ind-1, len, val, dp);
	int pick = INT_MIN;
	if((ind+1)<=len) pick = val[ind] + f(ind, len-ind-1, val, dp);
	return dp[ind][len] = max(pick, notpick); 
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n+1,-1));
	return f(n-1, n, price,dp);
}
//TABULATION
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n+1,0));
	for(int i=0;i<=n;i++) dp[0][i] = i*price[0];

	for(int i=1;i<n;i++){
		for(int j=0;j<n+1;j++){
			int notpick = dp[i-1][j];
			int pick = INT_MIN;
			if(j>=i+1) pick = price[i] + dp[i][j-i-1];
			dp[i][j] = max(pick, notpick);
		}
	}
	return dp[n-1][n];
}
//SPACE OPTIMIZATION
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> curr(n+1, 0);
	for(int i=0;i<=n;i++) curr[i] = i*price[0];

	for(int i=1;i<n;i++){
		for(int j=0;j<n+1;j++){
			int notpick = curr[j];
			int pick = INT_MIN;
			if(j>=i+1) pick = price[i] + curr[j-i-1];
			curr[j] = max(pick, notpick);
		}
	}
	return curr[n];
}
