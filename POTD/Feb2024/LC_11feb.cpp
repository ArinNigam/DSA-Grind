// Cherry Pickup 2 (Hard)
// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).

// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
// Total of cherries: 12 + 12 = 24.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int x,int y1,int y2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        
        if (y1<0 || y2<0 || y1>=m || y2>=n){
            return 0;
        }
        if (x==m){
            return 0;
        }
        if (dp[x][y1][y2]!=-1){
            return dp[x][y1][y2];
        }
        int maxi = 0;
        int ans = 0;
        ans += grid[x][y1];
        ans += grid[x][y2];
        for (int i = y1-1;i<=y1+1;i++){
            for (int j=y2-1;j<=y2+1;j++){
                if (i<j){
                    maxi = max(solve(x+1,i,j,grid,dp),maxi);
                }
            }
        }
        ans+=maxi;
        return dp[x][y1][y2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(0,0,n-1,grid,dp);
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
    auto ans = ob.cherryPickup(nums);
    cout<<ans;
    return 0;
}