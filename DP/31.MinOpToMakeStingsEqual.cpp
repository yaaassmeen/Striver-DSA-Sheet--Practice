int canYouMake(string &s1, string &s2){
    // Write your code here.
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1, 0), curr(m+1,0);
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]) curr[j] = 1+ prev[j-1];
            else curr[j] = max(curr[j-1], prev[j]);
        }
        prev = curr;
    }
    return (n-prev[m]) + (m-prev[m]);
}
