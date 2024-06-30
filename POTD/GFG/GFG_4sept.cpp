//Replace O's with X's
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void dfs(int x,int y,int n,int m,vector<vector<char>>&mat,vector<vector<int>>&vis){
        vis[x][y] = 1;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        bool flag =0;
        for (int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]=='O' && !vis[nx][ny]){
                dfs(nx,ny,n,m,mat,vis);
            }
        }
        return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(i == 0 or j == 0 or i == n-1 or j == m-1){
                    if (mat[i][j]=='O'){
                        dfs(i,j,n,m,mat,vis);
                    }
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (vis[i][j]==1){
                    mat[i][j] = 'O';
                }
                else if (mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
        
    }
};
signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<char>>nums(n,vector<char>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.fill(n,m,nums);
    return 0;
}