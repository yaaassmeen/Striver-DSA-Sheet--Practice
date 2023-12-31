//Recurssive
int f(int day, int last, vector<vector<int>> &points,) {
  if (day == 0) {
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return maxi;
  }
  int maxi = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points);
      maxi = max(maxi, activity);
    }
  }
  return  maxi;
}
int ninjaTraining(int n, vector < vector < int > > & points) {
  return f(n - 1, 3, points);
}

//Memoization
int f (int ind, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(ind == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
          if ( i != last) {
            maxi = max(maxi, points[0][i]);
          }
        }
        return maxi;
    }
    if(dp[ind][last] != -1) return dp[ind][last];
    int maxi = 0;
    for(int i=0;i<3;i++){
        
        if(i != last){
            maxi = max(maxi, points[ind][i] + f(ind-1, i, points, dp));
        }
    }
    return dp[ind][last]= maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n-1, 3, points, dp);
}


//Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for(int day = 1;day<n;day++){
        for(int last = 0;last < 4;last++){
            dp[day][last] = 0;
            for(int task = 0;task <=2;task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }  
    return dp[n-1][3];
}
