// All ancestors of a each node
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>temp;
    unordered_map<int,vector<int>>mp;
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node] = 1;
        vector<int>t(temp.begin(), temp.end());
        mp[node] = t;
        temp.push_back(node);
        for (auto it:adj[node]){
            if (!vis[it]){
                dfs(it,vis,adj);
            }
        }
        temp.pop_back();
        
    }
    void allAncestors(vector<vector<int>>&nums){
        int n = nums.size();
        vector<vector<int>>adj(n);
        for (int i=0;i<n;i++){
            adj[nums[i][0]].push_back(nums[i][1]);
        }
        vector<int>vis(n,0);
        dfs(1,vis,adj);
        for (auto it:mp){
            cout<<it.first<<": ";
            for (auto j:it.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i=0;i<n-1;i++){
        for (int j=0;j<2;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    ob.allAncestors(nums);
   
    return 0;
}