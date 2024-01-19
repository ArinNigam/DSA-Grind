// Minimum Falling Path Sum ( Medium )

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int row,int col,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        int n = matrix.size();
        if (row==n-1){
            return dp[row][col] = matrix[row][col];
        }
        if (dp[row][col]!=INT_MAX){
            return dp[row][col];
        }
        int left = INT_MAX,right = INT_MAX;
        if (col>0){
            left =solve(row+1,col-1,matrix,dp);
        }
        if (col<n-1){
            right = solve(row+1,col+1,matrix,dp);
        }
        
        dp[row][col] = matrix[row][col] + min({left,solve(row+1,col,matrix,dp),right});
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int ans = 1e9;
        for (int i=0;i<n;i++){
            ans = min(ans,solve(0,i,matrix,dp));
        }
        return ans;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(n));
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