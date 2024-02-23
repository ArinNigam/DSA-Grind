// Cheapest Flights Within K Stops

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city from_i to_i city with cost pi.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
// 5
// 0 1 100
// 1 2 100
// 2 0 100
// 1 3 600
// 2 3 200
// 0 3
// 1

// 700
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for (int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        vector<int>cost(n,1e9);
        cost[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps =  it.first;
            int node = it.second.first;
            int price = it.second.second;
            
            if (steps>k) break;
            for (auto it:adj[node]){
                int adjNode = it.first;
                int nextPrice = it.second;
                
                if (nextPrice + price < cost[adjNode] && steps <= k){
                    cost[adjNode] = nextPrice + price;
                    q.push({steps+1,{adjNode,cost[adjNode]}});
                } 
            }
        }
        return (cost[dst] == 1e9) ? -1 : cost[dst];
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(3));
    for (int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>nums[i][j];
        }
    }
    int src,dst;
    cin>>src>>dst;
    int k;
    cin>>k;
    Solution ob;
    auto ans = ob.findCheapestPrice(n,nums,src,dst,k);
    cout<<ans;
    return 0;
}