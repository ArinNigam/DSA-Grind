// Count Sub Islands (Medium)

// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.
// Input: 
// grid1 = 
//     [[1,1,1,0,0],
//     [0,1,1,1,1],
//     [0,0,0,0,0],
//     [1,0,0,0,0],
//     [1,1,0,1,1]], 
// grid2 = 
//     [[1,1,1,0,0],
//     [0,0,1,1,1],
//     [0,1,0,0,0],
//     [1,0,1,1,0],
//     [0,1,0,1,0]]
// Output: 3

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>&grid1,vector<vector<int>>&grid2,bool &flag){
        int n = grid1.size();
        int m = grid1[0].size();

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        grid2[x][y] = 0;
        if (grid1[x][y] == 0){
            flag = 0;
        }
        for(int i = 0 ;i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx>=0 && ny>=0 && nx < n && ny < m && grid2[nx][ny] == 1){
                
                dfs(nx,ny,grid1,grid2,flag);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid2[i][j] == 1){
                    bool flag = 1;
                    dfs(i,j,grid1,grid2,flag);
                    if (flag){
                        cnt++;
                    }
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
    vector<vector<int>>grid1(n,vector<int>(m)),grid2(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            cin >> grid1[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid2[i][j];
        }
    }
    Solution ob;
    auto ans = ob.countSubIslands(grid1,grid2);
    cout<<ans;
    return 0;
}