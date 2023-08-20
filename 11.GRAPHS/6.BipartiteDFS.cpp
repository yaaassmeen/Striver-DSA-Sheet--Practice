//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
//Adjacent list is given
// } Driver Code Ends
class Solution {
    bool dfs(int node, int col, vector<int> adj[], int color[]){
        color[node] = col;
        for(auto it: adj[node]){
        if(color[it] == -1){
            if(dfs(it, !col, adj, color) == false)return false;
        }
        else if(color[it] == col){
            return false;
        }
        return true;
        }
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++) color[i] = -1;
	    for(int i=0;i<V;i++){
	        if(color[i] == -1){
	            bool ans = dfs(i, 0, adj, color);
	            if(!ans) return ans;
	        }
	    }
	    return true;
	    
	}

};
//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends