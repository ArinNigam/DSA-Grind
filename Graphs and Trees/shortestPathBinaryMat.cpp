// Shortest Path on Binary Matrix
// Dijkstra with queue
// {steps,{x,y}}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n==1){
            if (grid[0][0]==0) return 1;
            else return -1;
        }
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int,pair<int,int>>>q;
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        q.push({1,{0,0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int step = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            for (int i=-1;i<=1;i++){
                for (int j=-1;j<=1;j++){
                    int nx = x + i;
                    int ny = y + j;
                    if (nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && step + 1 < dist[nx][ny]){
                        dist[nx][ny] = 1+ step;
                        if (nx == n-1 && ny == n-1){
                            return step+1;
                        }
                        q.push({1+step,{nx,ny}});
                    }
                }
            }
        }
        return -1;
        
    }   
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.shortestPathBinaryMatrix(nums);
    cout<<ans;
    return 0;
}