// Network Delay Time 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for (auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>q;
        q.push({0,k});
        
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        
        while(!q.empty()){
            int node = q.front().second;
            int time = q.front().first;
            q.pop();
            for (auto it: adj[node]){
                int adjNode = it.first;
                int t = it.second;
                if (t+time < dist[adjNode]){
                    dist[adjNode] = t+time;
                    q.push({t+time,adjNode});  
                }
                
            }
        }
        int ans= 0;
        for (int i=1;i<n+1;i++){
            if (dist[i]==1e9){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
signed main()
{    
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>nums(n,vector<int>(m));
    for (int i=0;i<m;i++){
        for (int j=0;j<3;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.networkDelayTime(nums,n,k);
    cout<<ans;
    return 0;
}