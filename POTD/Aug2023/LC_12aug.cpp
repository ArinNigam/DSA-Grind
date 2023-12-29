//  Unique Paths II ( Medium )
//  You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int i,int j,vector<vector<int>>& nums,vector<vector<int>>& dp){
        if (i<0 || j<0 || nums[i][j]==1)
            return 0;
      
        if (i==0 && j==0){
            return 1;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = 0;
        int left = 0;
        if(i>0)  up = func(i-1,j,nums,dp);
        if(j>0) left = func(i,j-1,nums,dp);
      
        return dp[i][j] = up+left;
      
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][1] = 1;
        for (int i=1;i<=n;i++){
          for (int j=1;j<=m;j++){
            if (obstacleGrid[i-1][j-1]==0){
              dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
          }
        }
        return dp[n][m];
    }
};

signed main()
{    
    int m,n;
    cin>>m>>n;
    vector<vector<int>>nums(m,vector<int>(n));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.uniquePathsWithObstacles(nums);
    cout<<ans;
    return 0;
}