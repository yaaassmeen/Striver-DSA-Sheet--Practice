//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class SolutionusingTopologicalSort{
    public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        int indegree[V] = {0};
        vector<int> rev[V];
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0)q.push(i);
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: rev[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }

        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

class Solution {
    bool dfs(int vis[], int pathVis[], int node, vector<int> adj[], int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        //traverse for adjacent nodes
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(vis, pathVis, it, adj, check)==true){
                    check[node] = 0;
                    return true;
                }
            }
            //if node had been previously visited 
            //but it has to be visited on the same path
            else if(pathVis[it]){
                check[node] = 0;
                return true;
            }
        }
        //if loop reaches here means no loop
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        vector<int> safeNodes;
        int check[V];
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(vis, pathVis, i, adj, check); 
            }
        }
        for(int i=0;i<V;i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        SolutionusingTopologicalSort o;
        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
