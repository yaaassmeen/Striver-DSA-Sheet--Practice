//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void solve(int col, vector<string> &board, vector<vector<int>> &ans, vector<int> &a, vector<int> &leftR, vector<int> &upperD, vector<int> &lowerD, int n){
        if(col == n){
            ans.push_back(a);
            return;
        }
        for(int row = 0;row<n;row++){
            if(leftR[row] == 0 && upperD[n-1+col-row] == 0 && lowerD[row+col] == 0){
                board[row][col] = 'Q';
                a.push_back(row+1);
                leftR[row] = 1;
                upperD[n-1+col-row] = 1;
                lowerD[row+col] = 1;

                solve(col+1, board, ans, a, leftR, upperD, lowerD, n);
                board[row][col] = '.';
                a.pop_back();
                leftR[row] = 0;
                upperD[n-1+col-row] = 0;
                lowerD[row+col] = 0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> a;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i] = s;
        vector<int> leftR(n,0), upperD(2*n-1, 0), lowerD(2*n-1,0);
        solve(0, board, ans, a, leftR, upperD, lowerD, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
