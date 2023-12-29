#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<vector<pair<int,int>>>&adj,int src){
        // u->{v,w}
        int n = adj.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            // traverse karo uske neighbours
            for (auto i:adj[node]){
                int adjNode = i.first;
                int edgeW = i.second;
                if (dis + edgeW < dist[adjNode]){
                    dist[adjNode] = dis + edgeW;        
                    pq.push({dis+edgeW,adjNode});   
                }
            }
            
        }
        return dist;
    }
};

signed main()
{    
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>>nums(n);
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        nums[u].push_back({v,w});
    }
    Solution ob;
    auto ans = ob.solve(nums,k);
    for (auto i:ans){
      cout<<i<<" ";
    }
    return 0;
}