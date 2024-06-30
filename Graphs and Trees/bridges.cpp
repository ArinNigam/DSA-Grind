#include<bits/stdc++.h>
using namespace std;

// 12 14
// 1 2
// 2 3
// 3 4
// 4 1
// 4 5
// 5 6
// 8 7
// 7 6
// 6 9
// 8 10
// 8 9
// 10 11
// 11 12
// 12 10

class Solution {
private:
    int timer = 1;
    void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,
        vector<vector<int>>&ans,vector<int>&low,vector<int>&tin){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto neighbour:adj[node]){
            if (neighbour==parent) continue;
            if (vis[neighbour]==0){
                dfs(neighbour,node,vis,adj,ans,low,tin);
                low[node] = min(low[neighbour],low[node]);
                
                if (low[neighbour] > tin[node]){
                    ans.push_back({neighbour,node});
                }
            }
            else{
                low[node] = min(low[neighbour],low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>low(n+1),tin(n+1),vis(n+1,0);
        vector<vector<int>>adj(n+1);
        for (auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>ans;
        dfs(1,-1,vis,adj,ans,low,tin);
        return ans;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(m+1,vector<int>(2));
    for (int i=0;i<m;i++){
        for (int j=0;j<2;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.criticalConnections(n,nums);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}