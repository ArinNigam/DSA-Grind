#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>&values,vector<vector<pair<int,int>>>&adj,int &maxTime,int &ans,int time,int val){
        if (time > maxTime) return;
        if (vis[node]==0){
            val+= values[node];
        }

        vis[node]++;
        
        if (node==0){
            ans = max(val,ans);
        }
        for (auto it : adj[node]){
            int adjNode = it.first;
            int t = time + it.second;
            dfs(adjNode,vis,values,adj,maxTime,ans,t,val);
        }

        vis[node]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int ans = values[0];
        vector<vector<pair<int,int>>>adj(n);
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>vis(n,0);
        dfs(0,vis,values,adj,maxTime,ans,0,0);
        return ans;
    }
    
    
};
signed main()
{    
    int n,m,max_t;
    cin>>n>>m>>max_t;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>edges(m,vector<int>(3));
    for (int i=0;i<m;i++){
        for (int j=0;j<3;j++){
            cin>>edges[i][j];
            
        }
    }
    Solution ob;
    auto ans = ob.maximalPathQuality(nums,edges,max_t);
    cout<<ans;
    return 0;
}