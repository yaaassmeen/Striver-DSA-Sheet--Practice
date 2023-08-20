#include<iostream>
#include<vector>
using namespace std;

class disjointSet{
    vector<int> rank, parent, size;
    public:
    disjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;    
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        if(rank[pu]  < rank[pv]){
            parent[pu] = pv;
        }else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        if(size[pu]  <size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
int main(){
    disjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findParent(3) == ds.findParent(7)){
        cout<<"Same"<<endl;
    }else cout<<"Not Same"<<endl;
    ds.unionByRank(3,7);
    if(ds.findParent(3) == ds.findParent(7)){
        cout<<"Same"<<endl;
    }else cout<<"Not Same"<<endl;
}