#include<iostream>
#include<vector>
using namespace std;

void dfs(int start, vector<int> adj[], int vis[],vector<int>& ans){
    vis[start] = 1;
    ans.push_back(start);
    for(auto it: adj[start]){
        if(!vis[it]){
            dfs(it, adj, vis, ans);
        }
    }
} 

vector<int> dfsT(int v, vector<int> adj[]){
    int vis[v];
    int start = 0;
    vector<int> ans;
    dfs(start, adj, vis, ans);
    return ans;
}

int main(){
    int v, e;
    cin>>v>>e;
    
    //Adjacency list Implementation
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int f, s;
        cin>>f>>s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    vector<int> ans = dfsT(v, adj);   
}