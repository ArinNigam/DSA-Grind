// Number of Ways to Arrive at Destination
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define pii pair<int,int>
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        for (auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n,1e9),ways(n,0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,0});
        const int mod = 1e9 + 7;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it: adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if (edW + dis < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis+edW,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edW == dist[adjNode]){
                    ways[adjNode] =  ( ways[adjNode] + ways[node] ) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(3));
    for (int i=0;i<m;i++){
        for (int j=0;j<3;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.countPaths(n,nums);
    cout<<ans;
    return 0;
}