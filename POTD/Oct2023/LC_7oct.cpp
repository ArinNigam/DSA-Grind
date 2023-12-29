// You should build the array arr which has the following properties:

// arr has exactly n integers.
// 1 <= arr[i] <= m where (0 <= i < n).
// After applying the mentioned algorithm to arr, the value search_cost is equal to k.
// Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    int solve(int n,int m,int k,int prev,vector<vector<vector<int>>>&dp){
        if (n==0){
            if (k==0) return 1;
            else return 0;
        }
         if (dp[n][k][prev]!=-1){
            return dp[n][k][prev];
        }
        int ans = 0;
        for (int i =1;i<=m;i++){
            if (k>0 && i>prev){
                ans = (ans+solve(n-1,m,k-1,i,dp))%mod;
            }
            else if(i<=prev){
                ans = (ans + solve(n-1,m,k,prev,dp))%mod;
            }
        }
        return dp[n][k][prev] = ans%mod;
    }
    int numOfArrays(int n, int m, int k) {
        if (k>m) return 0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(m+1,-1)));
        return solve(n,m,k,0,dp);
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.numOfArrays(nums);
    cout<<ans;
    return 0;
}