// Longest Increasing Subsequence ( Medium )

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int curr,int prev,vector<int>&nums,vector<vector<int>>&dp){
        int n = nums.size();
        if (curr==n){
            return 0;
        }
        if (dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int notTake = 0 + func(curr+1,prev,nums,dp);
        int take = 0;
        if (prev==-1 || nums[curr] > nums[prev]){
            take= 1 + func(curr+1,curr,nums,dp);
        }
        return dp[curr][prev+1] = max(take,notTake);
        
    }
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(0,-1,nums,dp);
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
    auto ans = ob.lengthOfLIS(nums);
    cout<<ans;
    return 0;
}