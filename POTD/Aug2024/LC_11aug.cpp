// Minimum Number of Days to Disconnect Island (Hard)

// You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
// The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
// In one day, we are allowed to change any single land cell (1) into a water cell (0).
// Return the minimum number of days to disconnect the grid.

// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 2
// Explanation: We need at least 2 days to get a disconnected grid.
// Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer;
    unordered_map<int,int>tin,low;
    bool flag =0;
    void dfs(int node,int parent,unordered_map<int,vector<int>>&adj){
        low[node] = tin[node] = timer;
        timer++;
        int child = 0;
        for (auto it:adj[node]){
            if (it==parent) continue;
            if (!low.count(it)){
                dfs(it,node,adj);
                low[node] = min(low[node],low[it]);
                if (low[it] >= tin[node] && parent!=-1){
                    flag = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
            
        }
        if (child>1 && parent==-1){
            flag = 1;
        }

    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[]= {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]){
                    int ind = i*m + j;
                    adj[ind] = {};

                    for(int k = 0;k < 4;k ++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx >= 0 && ny>=0 && nx<n && ny < m && grid[nx][ny]){
                            int newInd = nx*m + ny;
                            adj[ind].push_back(newInd);
                        }
                    }
                }
            }
        }
        if (adj.size()<=1){
            return adj.size();
        }
        bool multi_dfs = 0;
        for(auto it:adj){
            if (!low.count(it.first)){
                if (multi_dfs){
                    return 0;
                }
                dfs(it.first,-1,adj);
                multi_dfs = 1;
            }
        }

        if (flag){
            return 1;
        }
        return 2;
    }
};

signed main()
{  
  int n,m;
  cin>>n>>m;
  vector<vector<int>>grid(n,vector<int>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }
  Solution ob;
  auto ans = ob.minDays(grid);
  cout<<ans;
  return 0;
}