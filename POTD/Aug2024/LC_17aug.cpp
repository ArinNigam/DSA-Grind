//  Maximum Number of Points with Cost (Medium)
 
//  You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.
// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
// Return the maximum number of points you can achieve.

// Input: points = [[1,2,3],[1,5,1],[3,1,1]]
// Output: 9
// Explanation:
// The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
// You add 3 + 5 + 3 = 11 to your score.
// However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
// Your final score is 11 - 2 = 9.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int row,int col,vector<vector<int>>&points,vector<vector<long long>>&dp){
        int n = points.size();
        int m = points[0].size();
        if (row >= n){
            return 0;
        }
        if (dp[row][col]!=-1){
            return dp[row][col];
        }
        long long maxi = 0;
        for(int i=0;i<m;i++){
            maxi = max(points[row][col] - abs(i-col) + solve(row+1,i,points,dp),maxi);
        }
        return dp[row][col] = maxi;
        
    }
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long>dp(m,0);
        for(int j=0;j<m;j++){
            dp[j] = points[0][j];
        }
        for(int i=1;i<n;i++){
            vector<long long> left(m,0),right(m,0);
            vector<long long> curr(m,0);

            left[0] = dp[0];
            for(int j=1;j<m;j++){
                left[j] = max(left[j-1],dp[j]+j);
            }
            
            right[m-1] = dp[m-1] - (m-1);
            for(int j=m-2;j>=0;j--){
                right[j] = max(right[j+1],dp[j]-j);
            }

            for(int j=0;j<m;j++){
                curr[j] = max(left[j] - j , right[j] + j) + points[i][j];
            }
            dp = curr;
        }
        return *max_element(dp.begin(),dp.end());
    }
    
};


signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>points(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>points[i][j];
        }
    }
    Solution ob;
    auto ans = ob.maxPoints(points);
    cout<<ans;
    return 0;
}