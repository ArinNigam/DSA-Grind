#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st){
        vis[node] = 1;
        for (auto i:adj[node]){
            int v = i.first;
            if (!vis[v]){
                dfs(v,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> solve(vector<vector<pair<int,int>>>&adj){
        int n = adj.size();
        stack<int>st;
        vector<int>vis(n,0);
        for (int i=0;i<n;i++){
            if (!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int>dist(n,1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for (auto it:adj[node]){
                int v = it.first;
                int w = it.second;
                if (dist[node] + w < dist[v]){
                    dist[v] = w+ dist[node];
                }
            }
        }
        for (int i=0;i<n;i++){
            if (dist[i]==1e9){
                dist[i] = -1;
            }
        }
        return dist;
        
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>nums(n);
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        nums[u].push_back({v,w});
    }
    Solution ob;
    auto ans = ob.solve(nums);
    for (auto i:ans){
      cout<<i<<" ";
    }
    return 0;
}