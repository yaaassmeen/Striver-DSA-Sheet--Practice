//Recurssive
int f(int ind, int target, vector<int> &arr){
	if(target == 0) return 1;
	if(ind==0) return arr[ind] == target;
	int notpick = f(ind -1, target, arr);
	int pick = 0;
	if(target >= arr[ind]) pick = f(ind-1, target-arr[ind], arr);
	return pick + notpick;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return f(n-1, k, arr);
}
//Memoization
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
	if(target == 0) return 1;
	if(ind==0) return arr[ind] == target;
	if(dp[ind][target] != -1) return dp[ind][target];
	int notpick = f(ind -1, target, arr, dp);
	int pick = 0;
	if(target >= arr[ind]) pick = f(ind-1, target-arr[ind], arr, dp);
	return dp[ind][target] = pick + notpick;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return f(n-1, k, arr, dp);
}
//Tabulation
int findWays(vector<int> &num, int k){
     int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    if(num[0]<=k)
        dp[0][num[0]] = 1;
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            int notTaken = dp[ind-1][target];
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];   
            dp[ind][target]= notTaken + taken;
        }
    }
    return dp[n-1][k];
}
//Space Optimization
int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<int> prev(k+1,0);
    prev[0] =1;
    if(num[0]<=k)
        prev[num[0]] = 1;
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(k+1,0);
        cur[0]=1;
        for(int target= 1; target<=k; target++){
            int notTaken = prev[target];
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
            cur[target]= notTaken + taken;
        }   
        prev = cur;
    }
    return prev[k];   
}
