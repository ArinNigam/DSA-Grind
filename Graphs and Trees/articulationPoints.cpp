#include<bits/stdc++.h>
using namespace std;

// INPUT
// 5 5
// 0 1
// 1 4
// 2 4
// 3 4
// 2 3

// 1 4

class Solution {
  public:
    int timer = 0;
    void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],
        vector<int>&ans,vector<int>&low,vector<int>&tin){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto neighbour:adj[node]){
            if (neighbour==parent ) continue;
            if (vis[neighbour]==0){
                dfs(neighbour,node,vis,adj,ans,low,tin);
                low[node] = min(low[neighbour],low[node]);
                
                if (low[neighbour] >= tin[node] && parent!=-1){
                    ans[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(tin[neighbour],low[node]);
            }
        }
        if (child > 1 && parent==-1){
            ans[node]=1;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int>low(n),tin(n),vis(n,0);
        vector<int>ans(n,0);
        for (int i=0;i<n;i++){
            if (!vis[i]){
                dfs(i,-1,vis,adj,ans,low,tin);
            }
        }
        vector<int> v;
        for (int i=0;i<n;i++){
            if (ans[i]==1){
                v.push_back(i);
            }
        }
        if (v.size()==0){
            return {-1};
        }
        else{
            return v;
        }
    }
};
signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(2));
    for (int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<int>adj[n];
    for (auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    Solution ob;
    auto ans = ob.articulationPoints(n,adj);
    for (auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}