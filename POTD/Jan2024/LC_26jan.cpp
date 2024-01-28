// Out of Boundary Paths ( Medium)
// There is an m x n grid with a ball.
// Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. 

// Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// Output: 6

// HINT- dp with 4 adjacent points sum of all possible paths 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    int solve(int x,int y,int maxMove,int m,int n,vector<vector<vector<int>>>&dp){
       
        if (maxMove<0){
            return 0;
        }
        if (x<0 || y<0 || x>=m || y>=n){
            return 1;
        }
        if (dp[x][y][maxMove]!=-1){
            return dp[x][y][maxMove];
        }
        int left = solve(x-1,y,maxMove-1,m,n,dp);
        int right = solve(x+1,y,maxMove-1,m,n,dp);
        int up = solve(x,y+1,maxMove-1,m,n,dp);
        int down = solve(x,y-1,maxMove-1,m,n,dp);
        
        return dp[x][y][maxMove] = (left%mod+right%mod+up%mod+down%mod)%mod;
    }
    int findPaths(int m,int n,int maxMove,int startRow,int startCol){
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(startRow,startCol,maxMove,m,n,dp);
    }
};

signed main()
{    
    int m,n;
    cin>>m>>n;
    int maxMove;
    cin>>maxMove;
    int startRow,startCol;
    cin>>startRow>>startCol;
    Solution ob;
    auto ans = ob.findPaths(m,n,maxMove,startRow,startCol);
    cout<<ans;
    return 0;
}