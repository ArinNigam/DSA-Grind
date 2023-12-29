#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

bool dfs(int node, int col, int color[], vector<vector<int>>& graph){
  color[node] = col;
  for (auto it: graph[node]){
    if (color[it]==-1){
      if(dfs(it,!col,color,graph)==false){
        return false;
      }
    }
    else if (color[it]==col){
      return false;
    }
  }
  return true;
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
  int color[n];
  for (int i=0;i<n;i++){
    color[i]=-1;
  }
  
  for (int i=0;i<n;i++){
    if (color[i]==-1){
      if (dfs(i,0,color,graph)==false){
        cout<<0;
        return 0;
      }
    }
  }
  cout<<1;
  return 0;
}