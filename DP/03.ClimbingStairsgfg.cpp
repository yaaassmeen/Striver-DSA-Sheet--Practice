//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void solve(int ind, vector<int> &steps, set<vector<int>> &ans, int n){
        if(ind == n){
            sort(steps.begin(),steps.end());
            ans.insert(steps);
            return;
        }
        for(int i=1;i<=2;i++){
            if(ind+i<=n){
                steps.push_back(i);
                solve(ind+i, steps, ans, n);
                steps.pop_back();
            }
        }
    }
	public:
		int nthStair(int n){
		    //  Code here
		    vector<int> steps;
		    set<vector<int>> ans;
		    solve(0, steps, ans, n);
		    return ans.size();
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
