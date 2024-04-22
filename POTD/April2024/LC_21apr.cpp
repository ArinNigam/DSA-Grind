// Find if Path Exists in Graph (Easy)

// There is a bi-directional graph with n vertices, where each vertex
// is labeled from 0 to n - 1 (inclusive). The edges in the graph are 
// represented as a 2D integer array edges, where each edges[i] = [ui, vi] 
// denotes a bi-directional edge between vertex ui and vertex vi. Every 
// vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node] = 1;
        for (auto it:adj[node]){
            if (!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        vector<vector<int>>adj(n);
        for (int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        
        dfs(src,adj,vis);
        
        if (vis[src]==vis[dst]){
            return true;
        }
        else{
            return false;
        }
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin>>nums[i][j];
        }
    }
    int src,dst;
    cin>>src>>dst;
    Solution ob;
    auto ans = ob.validPath(n,nums,src,dst);
    cout<<ans;
    return 0;
}