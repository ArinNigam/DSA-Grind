// Cheapest flights within k stops
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    # define ppi pair<int,pair<int,int>>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for (auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        // { stop , { node,cost }}
        priority_queue<ppi,vector<ppi>,greater<ppi>>q;
        q.push({0,{src,0}});
        
        vector<int>cost(n,1e9);
        cost[src] = 0;
        
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int price = it.second.second;

            if (stop>k) continue;

            for (auto it:adj[node]){
                int adjNode = it.first;
                int cst = it.second;
                if (cst + price < cost[adjNode] && stop <= k){
                    cost[adjNode] = cst + price;
                    q.push({stop+1,{adjNode,cst+price}});
                }
            }
        }
        if (cost[dst]==1e9) return -1;
        return cost[dst];
    }
};
signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n*(n-1)/2,vector<int>(3));
    for (int i=0;i<n*(n-1)/2-1;i++){
        for (int j=0;j<3;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    int src,dst,k;
    cin>>src>>dst>>k;
    auto ans = ob.findCheapestPrice(n,nums,src,dst,k);
    cout<<ans;
    return 0;
}