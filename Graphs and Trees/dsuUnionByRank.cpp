// Union by Rank
// O(1) Time Complexity 
// usually it's O(V+E) but with ultimate par it gets reduced to constant time
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;
public:
    void check(int x,int y){
        if (findUPar(x)==findUPar(y)){
            cout<<"Same"<<endl;
        }
        else{
            cout<<"Not Same"<<endl;
        }
    }
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for (int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ds.unionByRank(u,v);
    }
    int x,y;
    cin>>x>>y;
    ds.check(x,y);
    ds.unionByRank(x,y);
    ds.check(x,y);
    return 0;
}