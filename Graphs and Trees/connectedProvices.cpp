// Connnected Provices
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

void dfs(int parent,vector<int>adj[],vector<int>&vis ){
  vis[parent] = 1;
  for (auto i:adj[parent]){
    if (!vis[i]){
      dfs(i,adj,vis);
    }
  }
}

signed main()
{  
  int n;
  cin>>n;
  vector<vector<int>>g(n,vector<int>(n));
  for (int i=0;i<n;i++){
    for (int j=0; j<n;j++){
      cin>>g[i][j];
    }
  }
  vector<int>adj[n];
  for (int i=0;i<n;i++){
    for (int j=0; j<n;j++){
      if (g[i][j]){
        adj[i].push_back(j);
        adj[j].push_back(i);
        
      }
    }
  }
  vector<int>vis(n,0);
  int ans = 0;
  for (int i=0;i<n;i++){
    if (!vis[i]){
      dfs(i,adj,vis);
      ans++;
    }
  }
  
  cout<<ans;
  
  return 0;
}