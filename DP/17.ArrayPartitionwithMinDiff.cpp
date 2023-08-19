//Recurssive
//Memoization
bool subsetSumUtil(int ind, int target, vector < int > & arr, vector < vector 
< int >> & dp) {
  if (target == 0)
    return dp[ind][target]=true;

  if (ind == 0)
    return dp[ind][target] = arr[0] == target;

  if (dp[ind][target] != -1)
    return dp[ind][target];

  bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

  bool taken = false;
  if (arr[ind] <= target)
    taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken || taken;
}

int minSubsetSumDifference(vector < int > & arr, int n) {

  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector < vector < int >> dp(n, vector < int > (totSum + 1, -1));

  for (int i = 0; i <= totSum; i++) {
    bool dummy = subsetSumUtil(n - 1, i, arr, dp);
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;

}
//Tabulation
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = 0;
	sum = accumulate(arr.begin(),arr.end(),0);
	vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
	for(int i=0;i<n;i++) dp[i][0] = true;
	if (arr[0] <= sum) dp[0][sum] = true;
	for(int ind = 1;ind<n;ind++){
          for (int target = 0; target <= sum; target++) {
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
              take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take || nottake;
          }
    }
    int ans = 1e9;
	for(int i=0;i<=sum;i++){
		if(dp[n-1][i] == true){
			int diff = abs(i - (sum-i));
			ans = min(ans, diff);
		}
		
	}
    return ans;
}
