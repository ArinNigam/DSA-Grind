// Maximum Fruits to Collect

// 3 3 
// 0 0
// 2
// 0 5 2
// 5 3 60
// 6 50 70

// 3 4
// 2 2
// 3
// 2 1 4 2 
// 3 1 2 3
// 2 2 0 1
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int x,int y,vector<vector<int>>&mat,int k,vector<vector<int>>&vis){
        int m = mat.size();
        int n = mat[0].size();
        if (k == 0) return mat[x][y];
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        int ans = 0;
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny]){
                ans = max(ans,dfs(nx,ny,mat,k-1,vis));
            }
           
        }
        vis[x][y] = 0;
        return mat[x][y] + ans;;
    }
    int solve(int x,int y,vector<vector<int>>&mat,int k){
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        return dfs(x,y,mat,k,vis);
    }
};

signed main()
{    
    int m,n;
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n));
    int x,y;
    cin>>x>>y;
    int k;
    cin>>k;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    Solution ob;
    cout<<ob.solve(x,y,mat,k);
    
    return 0;
}