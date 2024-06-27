// Find Center of Star Graph (Easy)

// There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.1
// You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

// Input: edges = [[1,2],[2,3],[4,2]]
// Output: 2
// Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int maxi = 0;
        int center = 0;
        for(int i=1;i<=n;i++){
            if (adj[i].size() > maxi){
                maxi = adj[i].size();
                center = i;
            }
        }
        return center;
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>edges(n,vector<int>(2));
    for (int i=0;i<n-1;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    Solution ob;
    auto ans = ob.findCenter(edges);
    cout<<ans;
    return 0;
}