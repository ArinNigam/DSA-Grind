// Number Of Enclaves
// Land touching no boundary

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>&grid,int n,int m){
        grid[i][j] = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        for (int k = 0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]){
                dfs(nx,ny,grid,n,m);
            }
        }
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        for (int i=0;i<n;i++){
            for (int j = 0;j<m;j++){
                if ((grid[i][j]==1) && (i==0 || i==n-1 || j==0 || j==m-1)){
                    dfs(i,j,grid,n,m);
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
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
    auto ans = ob.numberOfEnclaves(nums);
    cout<<ans;
    return 0;
}