#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis){
  vis[row][col]=1;
  int n = grid.size();
  int m = grid[0].size();
  
  queue<pair<int,int>>q;
  q.push({row,col});
  while(!q.empty()){
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    for(int delRow = -1;delRow<=1;delRow++){
      for(int delCol = -1;delCol<=1; delCol++){
        int nrow = row + delRow;
        int ncol = col + delCol;
        
        if (nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol] ){
          vis[nrow][ncol]=1;
          q.push({nrow,ncol});
        }
      }
    }
  }
}  
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
  int cnt=0;
  vector<vector<int>>vis(n,vector<int>(m,0));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if(!vis[i][j] && grid[i][j]==1){
        cnt++;
        dfs(i,j,grid,vis);
      }
    }
  }
  cout<<cnt;
  return 0;
}