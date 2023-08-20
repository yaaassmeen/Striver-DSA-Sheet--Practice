//Replace O's with X's

#include <bits/stdc++.h>
using namespace std;


class Solution{
    void dfs(int row, int col,vector<vector<int>>& vis, vector<vector<char>>& mat, int delrow[], int delcol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        
        //check top, bottom, left, right
        for(int i=0;i<4;i++){
                int nrow= row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol]== 'O'){
                    dfs(nrow, ncol, vis, mat, delrow, delcol);
               }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //Traverse first ans last rows
        int delrow[] = {-1, 0 , 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0, j, vis, mat, delrow, delcol);
            }
            
            //last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1, j, vis, mat, delrow, delcol);
            }
        }
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            
            //last col
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, vis, mat, delrow, delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O' && !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends