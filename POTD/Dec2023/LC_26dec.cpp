// Minimum number of dice rolls to achieve a target
#include<bits/stdc++.h>
using namespace std;

// Top Down approach
class Solution {
public:
    const int mod = 1e9+7;
    int func(int n,int k,int target,vector<vector<int>>&dp){
        if (target==0 && n==0){
            return 1;
        }
        if (target<=0 || n==0){
            return 0;
        }
        if (dp[n][target]!=-1){
            return dp[n][target]%mod;
        }
        
        int ways = 0;
        for (int i=1;i<=k;i++){
            ways = (ways + func(n-1,k,target-i,dp))%mod;
        } 
        return dp[n][target] = ways%mod;
    }
    int solve(int n,int k,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return func(n,k,target,dp);
    }
};

signed main()
{    
    int n,k,target;
    cin>>n>>k>>target;
    
    Solution ob;
    auto ans = ob.solve(n,k,target);
    cout<<ans;
    
    return 0;
}