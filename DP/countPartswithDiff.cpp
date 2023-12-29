// count partitions with difference s1-s2 = D
#include<bits/stdc++.h>
using namespace std;

int solve(int ind,int sum,vector<int>& nums,vector<vector<int>>&dp){
    if (ind==0){
        if (sum==0 && nums[0]==0){
            return 2;
        }
        if (sum==0 || sum==nums[0]){
            return 1;
        }
        return 0;
    }
    if (dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    int notTake = solve(ind-1,sum,nums,dp);
    int take = 0;
    if (nums[ind]<=sum){
        take = solve(ind-1,sum-nums[ind],nums,dp);
    }
    return dp[ind][sum] = take+notTake;
}    
signed main()
{    
    int n,k;
    cin>>n>>k;
    int sum=0;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    
    if (sum-k<0) {cout<<0; return 0;}
    if ((sum-k)%2==1){cout<<0;return 0;}
    
    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<solve(n-1,(sum-k)/2,nums,dp);
   
    return 0;
}