// Path with Maximum Gold (Medium)
// In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.

// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
// Output: 24
// Explanation:
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// Path to get the maximum gold, 9 -> 8 -> 7.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid){
        int m = grid.size();
        int n = grid[0].size();
       
        if (i<0 || i>=m || j<0 || j>=n) return 0;
        if (grid[i][j]==0) return 0;
        
        int gold = grid[i][j];
        grid[i][j] = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        int maxi = gold;
        
        for (int k=0;k<4;k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            maxi = max(maxi,gold + dfs(nx,ny,grid));
        }
        
        grid[i][j] = gold;
        return maxi;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int maxi = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]!=0){
                    maxi = max(maxi,dfs(i,j,grid));
                }
            }
        }
        return maxi;
    }
};
signed main()
{    
    int m,n;
    cin>>m>>n;
    vector<vector<int>>nums(m,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.getMaximumGold(nums);
    cout<<ans;
    return 0;
}