#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;

void dfs(int row, int col, vector<vector<int>> &vis, 
  vector<vector<char>> &mat, int delrow[], int delcol[]) {
      vis[row][col] = 1; 
      int n = mat.size();
      int m = mat[0].size();
      
      // check for top, right, bottom, left 
      for(int i = 0;i<4;i++) {
          int nrow = row + delrow[i];
          int ncol = col + delcol[i]; 
          // check for valid coordinates and unvisited Os
          if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
          && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
              dfs(nrow, ncol, vis, mat, delrow, delcol); 
          }
    }
}
signed main()
{  
  int n,m;
  cin>>n>>m;
  vector<vector<char>>mat(n,vector<char>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin>>mat[i][j];
    }
  }

  // create a visited array
  vector<vector<int>> vis(n, vector<int>(m,0)); 
  
  int delrow[4] = {-1,0,1,0};
  int delcol[4] = {0,1,0,-1};

  // traverse first row and last row 
  for(int j = 0 ; j<m;j++) {
    
      // check for unvisited Os in the boundary rows
    
      // first row 
      if(!vis[0][j] && mat[0][j] == 'O') {
          dfs(0, j, vis, mat, delrow, delcol); 
      }
      
      // last row 
      if(!vis[n-1][j] && mat[n-1][j] == 'O') {
          dfs(n-1,j,vis,mat, delrow, delcol); 
      }
  }
  
  for(int i = 0;i<n;i++) {
    
      // check for unvisited Os in the boundary columns
    
      // first column 
      if(!vis[i][0] && mat[i][0] == 'O') {
          dfs(i, 0, vis, mat, delrow, delcol); 
      }
      
      // last column
      if(!vis[i][m-1] && mat[i][m-1] == 'O') {
          dfs(i, m-1, vis, mat, delrow, delcol); 
      }
  }
  
  // if unvisited O then convert to X
  for(int i = 0;i<n;i++) {
      for(int j= 0 ;j<m;j++) {
          if(!vis[i][j] && mat[i][j] == 'O') 
              mat[i][j] = 'X'; 
      }
  }
   

  for (auto i : mat){
    for (auto j : i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}