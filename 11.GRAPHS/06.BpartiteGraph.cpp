//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
//Adjacent list is given
// } Driver Code Ends
class Solution {
    bool check(int v, vector<int>adj[], int start, int color[]){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++) color[i] = -1;
	    for(int i=0;i<V;i++){
	        if(color[i] == -1){
	            bool ans = check(V, adj, i, color);
	            if(!ans) return ans;
	        }
	    }
	    return true;
	    
	}

};

//Adjacent matrix is given
/*
class Solution {
    bool bfs(int st, vector<vector<int>>& graph, vector<int>& color) {
        queue<pair<int,int>>q;
        color[st] = 0;
        q.push({st,0});
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            for(auto it: graph[p.first]){
                if(color[it]==-1){
                    color[it] = !p.second;
                    q.push({it,color[it]});
                }
                else if(color[it]==p.second){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};
*/

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
