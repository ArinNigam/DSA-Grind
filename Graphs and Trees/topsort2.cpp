// Topological Sort using BFS
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void bfs(vector<vector<int>>&g, vector<int>&ans){
    int n = g.size();
    vector<int>indegree(n);
      
    for (int i=0;i<n;i++){
      for (auto it:g[i]){
        indegree[it]++;
      }
    }
    queue<int>q;
    for (int i=0;i<n;i++){
      if(indegree[i]==0){
        q.push(i);
      }
    }
    while(!q.empty()){
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for (auto it: g[node]){
        indegree[it]--;
        if (indegree[it]==0){
          q.push(it);
        }
      }
    }
  }  
};

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
    vector<int>ans;
    Solution ob;
    ob.bfs(g,ans);
    for (auto i: ans){
      cout<<i<<" ";
    }
  
  return 0;
}

