#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];
  
vector<vector<int>> func(vector<vector<int>>& nums){
  int n = nums[0].size();
  int m = nums.size();
  
  // Visted And Distance Matrix
  vector<vector<int>>vis(m,vector<int>(n,0));
  vector<vector<int>>dist(m,vector<int>(n,0));
  
  // Making a queue that will store coordinate and step
  queue<pair<pair<int,int>,int>>q;
  
  // Traverse the matrix
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      // Start the BFS if it contain 0
      if (nums[i][j]==0){
        q.push({{i,j},0});
        vis[i][j] = 1;
      }
      else{
        vis[i][j]=0;
      }
    }
  }
  int dx[4] = {-1,0,1,0};
  int dy[4] = {0,1,0,-1};
  
  // Traverse the queue untill its empty
  while(!q.empty()){
    int x = q.front().first.first;
    int y = q.front().first.second;
    int steps = q.front().second;
    
    // Pop the element
    q.pop();
    
    dist[x][y] = steps;
    // Check the 4 directions
    for (int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      // Check for bounded conditions
      if (nx<0 || ny<0 || nx>=m || ny>= n || vis[nx][ny]==1) continue;
        
      // Mark it visted and push in queue
      vis[nx][ny] = 1;
      q.push({{nx,ny},steps+1});
    }
  }
  return dist;
}  
signed main()
{  
  int n,m;
  cin>>n>>m;
  vector<vector<int>>nums(m,vector<int>(n));
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      cin>>nums[i][j];
    }
  }
  for (auto i : func(nums)){
    for (auto j : i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}