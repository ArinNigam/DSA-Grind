// Detecting Cycles in a graph using DFS

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long


bool dfs(int ind,int parent,vector<vector<int>>&graph,vector<int>&vis){
  vis[ind]=1;
  for (auto adj : graph[ind]){
    if (!vis[adj]){
      if(dfs(adj,ind,graph,vis)){
        return true;
      }
    }
    else if (adj!=parent) return true;
  }
  return false;
}  
signed main()
{  
  int n;
  cin>>n;
  vector<vector<int>>graph(n);
  for (int i=0;i<n;i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<int>vis(n,-1);
  for (int i=0;i<n;i++){
    if(!vis[i]){
      if (dfs(i,-1,graph,vis)) cout<< true;
      
    }
  }
  cout<< false;

}