// Most Stones Removed with Same Row or Column (Medium)

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj){
        vis[node] = 1;
        for(auto it:adj[node]){
            if (!vis[it]){
                dfs(it,node,vis,adj);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
              for(int j=i+1;j<n;j++){
                  if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                      adj[i].push_back(j);
                      adj[j].push_back(i);
                  }
              }
        }
        int num = 0;
        vector<int>vis(n,false);
        for(int i=0;i<n;i++){
            if (!vis[i]){
                dfs(i,-1,vis,adj);
                num++;
            }
        }
        return n - num;
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i=0;i<n;i++){
        cin>>nums[i][0] >> nums[i][1];
    }
    Solution ob;
    auto ans = ob.removeStones(nums);
    cout<<ans;
    return 0;
}