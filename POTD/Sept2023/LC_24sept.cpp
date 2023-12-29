// Champagne tower
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double solve(int poured,int row,int col,vector<vector<double>>&dp){
        if (row<0 || col<0 || col>row){
            return 0.0;
        }
        if (row==0 && col==0){
            return poured;
        }
        if (dp[row][col]!=-1){
            return dp[row][col];
        }
        double left = (solve(poured,row-1,col-1,dp)-1)/2;
        if (left<0) left = 0;
        double right = (solve(poured,row-1,col,dp)-1)/2;
        if (right<0) right = 0;
        return dp[row][col] = left+right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(query_row+1,vector<double>(query_glass+1,-1));
        return min(1.0,solve(poured,query_row,query_glass,dp));
    }
};
signed main()
{    
    int n;
    cin>>n;
    int row,col;
    cin>>row>>col;
    Solution ob;
    auto ans = ob.champagneTower(n,row,col);
    cout<<ans;
    return 0;
}