// Minimum Falling Path Sum II (Hard)

// Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
// A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
// Output: 13
// Explanation: 
// The possible falling paths are:
// [1,5,9], [1,5,7], [1,6,7], [1,6,8],
// [2,4,8], [2,4,9], [2,6,7], [2,6,8],
// [3,4,8], [3,4,9], [3,5,7], [3,5,9]
// The falling path with the smallest sum is [1,5,7], so the answer is 13.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int mini = INT_MAX;
        if(i==grid.size()-1){
            return grid[i][j];
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=0;k<grid[0].size();k++){
            if( abs(k-j) > 0){
                mini = min(mini,grid[i][j] + solve(i+1,k,grid,dp));
            }
        }
        return dp[i][j] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for (int i=0;i<grid.size();i++){
            mini = min(mini,solve(0,i,grid,dp));
        }
        return mini;
    }
};
signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(m,-1));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.minFallingPathSum(nums);
    cout<<ans;
    return 0;
}