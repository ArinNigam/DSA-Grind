// Minimum Spanning Tree
// Kruskal Algorithm 
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
      rank.resize(n+1);
      parent.resize(n+1);
      
      for (int i=0;i<n;i++){
          parent[i] = i;
      }
    }  
    
    int find(int node){
        if( parent[node]==node){
            return node;
        }
        
        return parent[node] = find(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int super_parent_u = find(u);
        int super_parent_v = find(v);
        
        if (super_parent_u == super_parent_v) return;
        
        if (rank[super_parent_u] > rank[super_parent_v]){
            parent[super_parent_v] = super_parent_u;
        }
        else if (rank[super_parent_u] < rank[super_parent_v]){
            parent[super_parent_u] = super_parent_v;
        }
        else{
            parent[super_parent_v] = super_parent_u;
            rank[super_parent_u] ++;
        }
    }
};
class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>edges;
        
        for (int i=0;i<V;i++){
            for (int j=0;j<adj[i].size();j++){
                edges.push_back({adj[i][j][1],{i,adj[i][j][0]}});
            }
        }
        sort(edges.begin(),edges.end());
        
        DisjointSet ds = DisjointSet(V);
        int sum = 0;
        for (int i=0;i<edges.size();i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int wt = edges[i].first;
            
            if (ds.find(u)!=ds.find(v)){
                ds.unionByRank(u,v);
                sum+=wt;
            }
        }
        
        return sum;
        
    }
};
signed main()
{    
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj[V];
    int i=0;
    while (i++<E) {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1,t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    
    Solution ob;
    auto ans = ob.spanningTree(V,adj);
    cout<<ans;
    return 0;
}