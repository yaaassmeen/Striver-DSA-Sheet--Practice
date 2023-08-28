#include <bits/stdc++.h> 
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string s1 = s;
        reverse(s1.begin(),s1.end());
        int n = s.size();
        vector<int> prev(n+1, 0), curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == s1[j-1]) curr[j] = 1+ prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return prev[n];
}
