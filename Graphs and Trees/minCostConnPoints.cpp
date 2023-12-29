// 5
// 0 0
// 2 2
// 3 10
// 5 2
// 7 0

// 20
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define pii pair<int,int>
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pii>adj[n];
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int dis = abs(abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]));
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }

        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<int>vis(n,0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int edW = it.first;
            if (vis[node] == 1) continue;
            vis[node] = 1;
            sum+=edW;
            for (auto it:adj[node]){
                int adjNode = it.first;
                int dis = it.second;
                if (!vis[adjNode]){
                    pq.push({dis,adjNode});
                }
            }
        }
        return sum;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.minCostConnectPoints(nums);
    cout<<ans;
    return 0;
}