// Kahn's Algo
#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& adj){
  int n = adj.size();
  vector<int>indegree(n);
  for (int i=0;i<n;i++){
    for (auto it: adj[i]){
      indegree[it]++;
    }
  }
  
  queue<int>q;
  for (int i=0;i<n;i++){
    if (indegree[i]==0){
      q.push(i);
    }
  }
  int cnt=0;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    cnt++;
    for (auto it : adj[node]){
      indegree[it]--;
      if (indegree[it]==0){
        q.push(it);
      }
    }
  }
  if (cnt==n) return false;
  return true;
}  
signed main()
{  
  int n;
  cin>>n;
  vector<vector<int>>g(n);
  for (int i=0;i<n;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
  }
  cout<<bfs(g);
  
  return 0;
}