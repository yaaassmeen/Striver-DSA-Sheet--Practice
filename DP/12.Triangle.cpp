class Solution {
//     int func(int i, int j, vector<vector<int>>& triangle){
//         if(i == triangle.size()-1) {
//             return triangle[i][j];
//         }
//         int down = triangle[i][j] + func(i+1, j, triangle);
//         int diag = triangle[i][j] + func(i+1, j+1, triangle);
//         return min(down, diag);
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return func(0,0,triangle);
//     }
//     int func(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
//         if(i == triangle.size()-1) {
//             return triangle[i][j];
//         }
//         if(dp[i][j] !=-1)return dp[i][j];
//         int down = triangle[i][j] + func(i+1, j, triangle, dp);
//         int diag = triangle[i][j] + func(i+1, j+1, triangle, dp);
//         return dp[i][j] = min(down, diag);
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         int m = triangle[n-1].size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         return func(0,0,triangle, dp);
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         int m = triangle[n-1].size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         for(int i=0;i<m;i++){
//             dp[n-1][i] = triangle[n-1][i];
//         }
//         for(int i=n-2;i>=0;i--){
//             for(int j=triangle[i].size()-1;j>=0;j--){
//                 int down = triangle[i][j] + dp[i+1][j];
//                 int diag = triangle[i][j] + dp[i+1][j+1];
//                 dp[i][j] = min(down, diag);
//             }
//         }
//         return dp[0][0];
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<int> front(n,0);
        for(int i=0;i<m;i++){
            front[i] = triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=triangle[i].size()-1;j>=0;j--){
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];
                curr[j] = min(down, diag);
            }
            front = curr;
        }
        return front[0];
    }
};
