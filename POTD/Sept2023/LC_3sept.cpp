#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int uniquePaths2(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double res=1;
        for (int i=1;i<=r;i++){
            res = res * (N - r + i)/i;
        }
        return (int)res;
    }
    int uniquePaths1(int m, int n) {
            vector<vector<int>>dp(m,vector<int>(n,0));
            for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
            
                int up=0;
                int right=0;
                if (i>0){
                    up= dp[i-1][j];
                }
                if (j>0){
                    right = dp[i][j-1];
                }   
                dp[i][j]= up + right;
            }
        }
        return dp[m-1][n-1];
    
    }
    int func(int i,int j,vector<vector<int>>&dp){
        if (i==0 && j==0) return 1;
        if(i<0 || j< 0 ) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int up = func(i-1,j,dp);
        int down = func(i,j-1,dp);
        return dp[i][j] = up + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp);
        
    }
};
signed main()
{    
    int n,m;
    cin>>n>>m;
    
    Solution ob;
    auto ans = ob.uniquePaths(m,n);
    cout<<ans;
    return 0;
}