#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>>adj(n);
        vector<int>height(n,0);
        for (int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            height[edges[i][0]]++;
            height[edges[i][1]]++;
        }
        
        queue<int>q;
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if (height[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int nn = q.size();
            ans.clear();
            while(nn--){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto it:adj[node]){
                    height[it]--;
                    if (height[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        return ans;
        
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>edges(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    Solution ob;
    auto ans = ob.findMinHeightTrees(n,edges);
    for (auto i:ans){
      cout<<i<<" ";
    }
    return 0;
}