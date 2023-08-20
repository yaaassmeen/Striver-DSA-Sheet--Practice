#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//TC: O(N) + O(2E)
//SC: O(3N)
vector<int> bfs(int v, vector<int> adj[]){
    int vis[v] = {0};
    vis[0] = 1;
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return bfs;
}

int main(){
    int v, e;
    cin>>v>>e;
    //Adjacency Matrix Implementation
    int adjM[v+1][e+1];
    for(int i=0;i<e;i++){
        int f, s;
        cin>>f>>s;
        adjM[f][s] = 1;
        adjM[s][f] = 1;
    }
    //Adjacency list Implementation
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int f, s;
        cin>>f>>s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    vector<int> ans = bfs(v, adj);   
}