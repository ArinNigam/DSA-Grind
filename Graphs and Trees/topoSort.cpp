#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

void dfs(int node,stack<int>&st, vector<vector<int>>&g, vector<int>&vis){
  vis[node]=1;
  for (auto it : g[node]){
    if(!vis[it]) dfs(it,st,g,vis);
  }
  st.push(node);
}  
signed main()
{  
  int n;
  cin>>n;
  vector<vector<int>>g(n);
  for (int i=0;i<n;i++){
    int u,v;
    cin>>u>>v;
    g[v].push_back(u);
  }
  vector<int>vis(n,0);
  stack<int>st;
  for (int i=0;i<n;i++){
    if (!vis[i]){
      dfs(i,st,g,vis);
    }
  }
  vector<int>ans;
  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  for (auto i: ans){
    cout<<i<<' ';
  }
  
  return 0;
}