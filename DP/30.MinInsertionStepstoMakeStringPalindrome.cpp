//size of string - size of longest palindromic subsequence already present in the string.
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<int> prev(n+1,0), curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(s[i-1] == s1[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return n-prev[n];
    }
};
