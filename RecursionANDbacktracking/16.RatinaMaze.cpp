//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    void solve(int i, int j, vector<vector<int>> &m, int n,  vector<vector<int>> &vis, string move, vector<string> &ans){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        //down
        if(i+1<n && vis[i+1][j] != 1 && m[i+1][j] == 1){
            vis[i][j] = 1;
            solve(i+1, j, m, n, vis, move + 'D', ans);
            vis[i][j] = 0;
        }
        //left
        if(j-1>=0 && vis[i][j-1] != 1 && m[i][j-1] == 1){
            vis[i][j] = 1;
            solve(i, j-1, m, n, vis, move + 'L', ans);
            vis[i][j] = 0;
        }
        //right
        if(j+1<n && vis[i][j+1] != 1 && m[i][j+1] == 1){
            vis[i][j] = 1;
            solve(i, j+1, m, n, vis, move + 'R', ans);
            vis[i][j] = 0;
        }
        //up
        if(i-1>=0 && vis[i-1][j] != 1 && m[i-1][j] == 1){
            vis[i][j] = 1;
            solve(i-1, j, m, n, vis, move + 'U', ans);
            vis[i][j] = 0;
        }
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        if(m[0][0] == 1) solve(0, 0, m, n, vis, "",ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
