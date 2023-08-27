#include<bits/stdc++.h>
//Memoization
int f(int i1, int i2, string s1, string s2, vector<vector<int>> &dp){
        if(i1<0  || i2<0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s1[i1] == s2[i2]) return 1 + f(i1-1, i2-1, s1, s2,dp);
        else return dp[i1][i2] = max(f(i1-1, i2, s1, s2, dp), f(i1, i2-1, s1, s2, dp));
    }
int lcs(string text1, string text2)
{
	//Write your code here
	int ind1 = text1.size(), ind2 = text2.size();
	string s1 = text1, s2 = text2;
	vector<vector<int>> dp(ind1+1, vector<int>(ind2+1, -1));
  return f(ind1-1, ind2-1, text1, text2, dp);
}
//Tabulation
int lcs(string text1, string text2)
{
	//Write your code here
	int ind1 = text1.size(), ind2 = text2.size();
	string s1 = text1, s2 = text2;
	vector<vector<int>> dp(ind1+1, vector<int>(ind2+1, -1));
	for(int i=0;i<=ind1;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=ind2;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=ind1;i++){
            for(int j=1;j<=ind2;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[ind1][ind2];
}
//Space Optimization
    int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size(), ind2 = text2.size();
        if(text1 == text2) return ind1;
        string s1 = text1, s2 = text2;
        vector<int> prev(ind2+1, 0);
        vector<int> curr(ind2+1, 0);
        for(int i=1;i<=ind1;i++){
            for(int j=1;j<=ind2;j++){
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev= curr;
        }
        return prev[ind2];
    
    }
