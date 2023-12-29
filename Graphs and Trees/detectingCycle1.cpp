// Detecting Cycles in a graph using BFS

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

bool bfs(int ind, vector<vector<int>>& graph,vector<int>&vis){
  vis[ind] =1;
  queue<int>q;
  q.push(ind);
  while(!q.empty()){
    int parent = q.front();
    q.pop();
    for (auto adj_neighbour : graph[parent]){
      if (!vis[adj_neighbour]){
        vis[adj_neighbour] = 1;
        q.push(adj_neighbour);
      }
      else if (parent!=adj_neighbour){
        return 1;
      }
    }
  }
  return 0;
  
}  
signed main()
{  
  int n;
  cin>>n;
  vector<vector<int>>graph(n);
  vector<int>vis(n,0);
  for (int i=0;i<n;i++){
    int u,v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i=0;i<n;i++){
    if (!vis[i]){
      if (bfs(i,graph,vis))
        cout<< 1;
    }
  }
  cout<<0;
  
  
  return 0;
}