#include <bits/stdc++.h>
using namespace std;

class Solution {
    //using bfs
    void bfs(int row, int col , vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int,int> > q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse in neighbour;
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1;delcol <= 1;delcol++){
                    int i = row+delrow;
                    int j = col+delcol;
                    if(i >=0 && i<n  && j >=0 && j<m && grid[i][j] =='1' && !vis[i][j]){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
    }
    //using dfs
        void dfs(const vector<vector<char>>& grid, 
             vector<vector<int>>& vis, 
             int i, int j, int n, int m)    {
        
        if(i<0 || i>=n || j<0 || j>=m ||
          vis[i][j]==1|| grid[i][j]=='0')
            return;
        
        vis[i][j] = 1;
        
        dfs(grid, vis, i+1, j, n, m);//for lower cell
        dfs(grid, vis, i-1, j, n, m);//for upper cell
        dfs(grid, vis, i, j+1, n, m);//for right  cell
        dfs(grid, vis, i, j-1, n, m);//for left cell
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
    
    //VISITED GRID WITH INITIAL VALUES = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j = 0 ;j<m;j++){
            if(!vis[i][j] && grid[i][j] =='1'){
                count++;
                //bfs(i, j, vis, grid);
                dfs(grid, vis, i, j, n, m);
            }
        }
    }
    return count;
    }
};
