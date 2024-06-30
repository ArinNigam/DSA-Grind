// Remove Max Number of Edges to Keep Graph Fully Traversable (Hard)
// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.
// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;
    int cnt;
public:
    DisjointSet(int n){
        cnt = n;
        parent.resize(n + 1);
        size.resize(n + 1,1);
        for (int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findRoot(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findRoot(parent[node]);
    }
    bool unionBySize(int u,int v){
        int rootU = findRoot(u);
        int rootV = findRoot(v);
        if (rootU == rootV) return false;
        if (size[rootU] < size[rootV]){
            parent[rootU] = rootV;
            size[rootV]+=size[rootU];
        }
        else{
            parent[rootV] = rootU;
            size[rootU]+= size[rootV];
        }
        cnt--;
        return true;
    }
    
    bool isConnected(){
        return cnt==1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int edgeAdded= 0;
        DisjointSet alice(n),bob(n);
        for(auto edge:edges){
            if (edge[0]==3){
                if (alice.unionBySize(edge[1],edge[2]) | bob.unionBySize(edge[1],edge[2])){
                    edgeAdded++;
                }
            }
        }
        
        for(auto edge:edges){
            if (edge[0]==1){
                if (alice.unionBySize(edge[1],edge[2])){
                    edgeAdded++;
                }
            }
            else if(edge[0]==2){
                if(bob.unionBySize(edge[1],edge[2])){
                    edgeAdded++;
                }
            }
        }
        if (alice.isConnected() && bob.isConnected()){
            return edges.size() - edgeAdded;
        }
        return -1;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(m,vector<int>(3));
    for (int i=0;i<m;i++){
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    }
    Solution ob;
    auto ans = ob.maxNumEdgesToRemove(n,nums);
    cout<<ans;
    return 0;
}