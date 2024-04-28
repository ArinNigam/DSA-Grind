// Sum of Distances in Tree (Hard)

// There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
// You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
// Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

// Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: The tree is shown above.
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.
// Hence, answer[0] = 8, and so on.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs1(int node,int par,vector<vector<int>>&adj,vector<int>&cnt,vector<int>&sum){
        int ans =0;
        int val =0; 
        for (auto it:adj[node]){
            if (it!=par){
                ans+=dfs1(it,node,adj,cnt,sum);
                val+=sum[it];
            }
        }
        sum[node] = ans+val;
        return cnt[node] = ans+1;
    }
    
    void dfs2(int node,int par,vector<vector<int>>&adj,vector<int>&cnt,vector<int>&sum,int n){
        for(auto it:adj[node]){
            if(it!=par){
                sum[it]+=sum[node]- (sum[it] + cnt[it]) + (n-cnt[it]);
                dfs2(it,node,adj,cnt,sum,n);
            }
            
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for (auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>cnt(n,0);
        vector<int>sum(n,0);
        
        dfs1(0,-1,adj,cnt,sum);
        dfs2(0,-1,adj,cnt,sum,n);
        return sum;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>edges(n,vector<int>(2,-1));
    for (int i=0;i<n-1;i++){
        for (int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    
    Solution ob;
    auto ans = ob.sumOfDistancesInTree(n,edges);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}