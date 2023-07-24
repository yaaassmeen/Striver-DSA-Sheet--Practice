class Solution {
//     int func(int i, int j, vector<vector<int>>& matrix, int n){
//         if(j<0 || j>=n) return 1e9;
//         if(i == 0) return matrix[i][j];
//         int u = matrix[i][j] + func(i-1, j, matrix, n);
//         int l = matrix[i][j] + func(i-1, j-1, matrix, n);
//         int r = matrix[i][j] + func(i-1, j+1, matrix, n);
//         return min(u,min(l,r));
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = INT_MAX;
//         for(int i=0;i<n;i++){
//             int mini = func(n-1,i,matrix, n);
//             ans = min(mini,ans);
//         }
//         return ans;
//     }
//     int func(int i, int j, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp){
//         if(j<0 || j>=n) return 1e9;
//         if(i == 0) return matrix[i][j];
//         if(dp[i][j] != -1)return dp[i][j];
//         int u = matrix[i][j] + func(i-1, j, matrix, n, dp);
//         int l = matrix[i][j] + func(i-1, j-1, matrix, n, dp);
//         int r = matrix[i][j] + func(i-1, j+1, matrix, n, dp);
//         return dp[i][j] = min(u,min(l,r));
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = INT_MAX;
//         vector<vector<int>> dp(n,vector<int>(n, -1));
//         for(int i=0;i<n;i++){
//             int mini = func(n-1,i,matrix, n, dp);
//             ans = min(mini,ans);
//         }
//         return ans;
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n,vector<int>(n, -1));
//         for(int i=0;i<n;i++){
//             dp[0][i] = matrix[0][i];
//         }
//         for(int i=1;i<n;i++){
//             for(int j=0;j<n;j++){
//                 int u = matrix[i][j] + dp[i - 1][j];
//                 int l = matrix[i][j], r = matrix[i][j];
//                 if (j - 1 >= 0) {
//                     l += dp[i - 1][j - 1];
//                 }
//                 else l+= 1e9;
//                 if (j + 1 < n) {
//                     r += dp[i - 1][j + 1];
//                 }
//                 else r+= 1e9;
//                 dp[i][j] = min(u, min(l, r));
//             }
//         }
//         int ans = dp[n-1][0];
//         for(int i=1;i<n;i++){
//             ans = min(ans, dp[n-1][i]);
//         }
//         return ans;
//     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n , 0), curr(n,0);
        for(int i=0;i<n;i++){
            prev[i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int u = matrix[i][j] + prev[j];
                int l = matrix[i][j], r = matrix[i][j];
                if (j - 1 >= 0) {
                    l += prev[j - 1];
                }
                else l+= 1e9;
                if (j + 1 < n) {
                    r += prev[j + 1];
                }
                else r+= 1e9;
                curr[j] = min(u, min(l, r));
            }
            prev = curr;
        }
        int ans = prev[0];
        for(int i=1;i<n;i++){
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};
