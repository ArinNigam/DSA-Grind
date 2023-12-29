#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    #define ppi pair<int,pair<int,int>>
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            if (x == n-1 && y == m-1) return dis;
            for (int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx>=0 && ny>=0 && nx<n && ny<m){
                    int effort = max(dis,abs(heights[x][y]-heights[nx][ny]));
                    if (effort < dist[nx][ny]){
                        dist[nx][ny] = effort;
                        pq.push({effort,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.minimumEffortPath(nums);
    cout<<ans;
    return 0;
}