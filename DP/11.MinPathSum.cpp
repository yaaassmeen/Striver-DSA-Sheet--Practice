class Solution {
           //Recursive//
//     long long func(int i, int j, vector<vector<int>>& grid){
//         if(i == 0 && j == 0) return grid[i][j];
//         if(i<0 || j<0) return INT_MAX;
//         long long up = grid[i][j] + func(i-1, j, grid);
//         long long left = grid[i][j] + func(i, j-1, grid);
//         return min(up, left);
//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         return static_cast<int>(func(n - 1, m - 1, grid));
//     }
          //Memoization
// long long func(int i, int j, vector<vector<int>>& grid, vector<vector<long long>>& memo) {
//     if (i == 0 && j == 0) return grid[i][j];
//     if (i < 0 || j < 0) return INT_MAX;
//     if (memo[i][j] != -1) return memo[i][j];

//     long long up = grid[i][j] + func(i - 1, j, grid, memo);
//     long long left = grid[i][j] + func(i, j - 1, grid, memo);

//     memo[i][j] = min(up, left);
//     return memo[i][j];
// }

// public:
// int minPathSum(vector<vector<int>>& grid) {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<long long>> memo(n, vector<long long>(m, -1));
//     return static_cast<int>(func(n - 1, m - 1, grid, memo));
// }
          //Tabulation//
// public:
// int minPathSum(vector<vector<int>>& grid) {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<long long>> memo(n, vector<long long>(m, -1));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(i==0&&j==0)memo[i][j] = grid[i][j];
//             else{
//             long long up = grid[i][j], left = grid[i][j];
//             if(i>0)up += memo[i - 1][j];
//             else up+=INT_MAX;
//             if(j>0)left += memo[i][j-1];
//             else left += 1e9;
//             memo[i][j] = min(up,left);
//             }
//         }
//     }
//     return static_cast<int>(memo[n-1][m-1]);
// }

          //Space Optimization
public:
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<long long> memo(m, 0);
    for (int i = 0; i < n; i++) {
        vector<long long> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else {
                long long up = grid[i][j] + (i > 0 ? memo[j] : 1e9);
                long long left = grid[i][j] + (j > 0 ? curr[j - 1] : 1e9);
                curr[j] = min(up, left);
            }
        }
        memo = curr;
    }
    return static_cast<int>(memo[m - 1]);
    }
    

};
