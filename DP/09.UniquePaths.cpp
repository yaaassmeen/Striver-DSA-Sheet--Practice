//Recursive
#include <bits/stdc++.h>
int f(int i, int j, int m, int n) {
	if(i<0 || j<0) return 0;
	if(i==0 && j==0) return 1;
	int up = f(i-1, j, m, n);
	int left = f(i, j-1, m, n);
	return up + left;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	return f(m-1, n-1, m, n);
}

//Memoization
#include <bits/stdc++.h>
int f(int i, int j, int m, int n, vector<vector<int>>& dp) {
	if(i<0 || j<0) return 0;
	if(i==0 && j==0) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	int up = f(i-1, j, m, n, dp);
	int left = f(i, j-1, m, n, dp);
	return dp[i][j] = up + left;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int> (n, -1));
	return f(m-1, n-1, m, n, dp);
}

//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            int up=0;
            int left =0;
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];           
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n-1];
    }
};
// ||
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int> (n, 0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
			}
			int up = 0, left = 0;
			if(i>0) 
            	up = dp[i-1][j];
          	if(j>0)
            	left = dp[i][j-1];
            dp[i][j] = up+left;

        }
	}
	return dp[m-1][n-1];
}
