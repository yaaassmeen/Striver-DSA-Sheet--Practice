#include <bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(int v, vector<int> adj[], int st, int vis[]) {
    vis[st] = 1;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}
public:
int numProvinces(vector<vector<int>>& adj, int V) {
    vector<int> adjc[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j] == 1 && i != j){
                adjc[i].push_back(j);
                adjc[j].push_back(i);
            }
        }
    }
    int count = 0;
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            bfs(V, adjc, i, vis);
            count++;
        }
    }
    return count;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends