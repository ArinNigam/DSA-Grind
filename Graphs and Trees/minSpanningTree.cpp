//Minimum Spanning Tree
// Prim's Algorithm
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<pair<int,int>>>& adj,int V){
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if (vis[node]==1) continue;
            
            vis[node] = 1;
            sum+=wt;
            for (auto it: adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                
                if (!vis[adjNode]){
                    pq.push({edgeW,adjNode});
                }
            }
        }
        return sum;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>nums(n);
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        nums[u].push_back({v,w});
        nums[v].push_back({u,w});
    }
    Solution ob;
    auto ans = ob.solve(nums,n);
    cout<<ans;
    return 0;
}