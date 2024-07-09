#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(int node,stack<int>&st,vector<int>&vis,vector<vector<int>>&adj){
    vis[node] = 1;
    for(auto it:adj[node]){
      if (!vis[it]){
        dfs(it,st,vis,adj);
      }
    }
    st.push(node);
  }
  int topoSort(vector<vector<int>>&nums){
    int n = nums.size();
    vector<vector<int>>adj(n);
    vector<int>vis(n,0);
    stack<int>st;
    for (int i=0;i<n;i++){
      if (!vis[i]){
        dfs(i,st,vis,adj);
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
  }
};

signed main()
{  
  int n;
  cin>>n;
  vector<vector<int>>nums(n,vector<int>(2));
  for (int i=0;i<n;i++){
    cin>>nums[i][0]>>nums[i][1];
  }
  Solution ob;
  auto ans = ob.topoSort(nums);
  cout<<ans;
  return 0;
}