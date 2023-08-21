#include <bits/stdc++.h> 
//Recurssive
int f(int ind, int wt, vector<int> &weight, vector<int> &val){
	if(ind == 0){
		if(weight[0]<=wt) return val[0];
		return 0;
	}
	int notpick = f(ind-1, wt, weight, val, dp);
	int pick = INT_MIN;
	if(weight[ind] <= wt) pick = val[ind] + f(ind-1, wt-weight[ind], weight, val
	,dp);
	return max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return f(n-1, maxWeight, weight, value);
}
//Memoization
int f(int ind, int wt, vector<int> &weight, vector<int> &val, 
vector<vector<int>> &dp){
	if(ind == 0){
		if(weight[0]<=wt) return val[0];
		return 0;
	}
	if(dp[ind][wt] != -1) return dp[ind][wt];
	int notpick = f(ind-1, wt, weight, val, dp);
	int pick = INT_MIN;
	if(weight[ind] <= wt) pick = val[ind] + f(ind-1, wt-weight[ind], weight, val
	,dp);
	return dp[ind][wt]  = max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return f(n-1, maxWeight, weight, value, dp);
}
//Tabulation
int knapsack(vector<int> weight, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1,0 ));
	for(int i=weight[0]; i<=maxWeight; i++){
        dp[0][i] = val[0];
    }

	for(int ind = 1;ind<n;ind++){
		for(int w = 0;w<=maxWeight;w++){
			int notpick = dp[ind-1][w];
			int pick = INT_MIN;
			if(weight[ind] <= w) pick = val[ind] + dp[ind-1]
			[w-weight[ind]];
			dp[ind][w]  = max(pick, notpick);
		}
	}
	return dp[n-1][maxWeight];
}
//Space Optimization
int knapsack(vector<int> weight, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight+1, 0);
	for(int i=weight[0]; i<=maxWeight; i++){
        prev[i] = val[0];
    }

	for(int ind = 1;ind<n;ind++){
		for(int cap=maxWeight; cap>=0; cap--){
            
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(weight[ind] <= cap)
                taken = val[ind] + prev[cap - weight[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
	}
	return prev[maxWeight];
}
