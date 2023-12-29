// Kahn's Algo
// finding outdegree
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj){
  int n = adj.size();
  vector<int>revAdj[n];
  vector<int>outdegree(n);
  for (int i=0;i<n;i++){
    for (auto it: adj[i]){
      revAdj[it].push_back(i);
      outdegree[i]++;
    }
  }
  
  queue<int>q;
  for (int i=0;i<n;i++){
    if (outdegree[i]==0){
      q.push(i);
    }
  }
  
  vector<int>ans;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto it : revAdj[node]){
      outdegree[it]--;
      if (outdegree[it]==0){
        q.push(it);
      }
    }
  }
  sort(ans.begin(),ans.end());
  for (auto i: ans){
    cout<<i<<" ";
  }
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
  bfs(g);
  
  return 0;
}