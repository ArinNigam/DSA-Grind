// maximise K elements sum from either left or right
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(int i,int j,vector<int>&nums,int k,int sum,vector<vector<int>>&dp){
        if (k==0) return sum;
        if (dp[i][j]!=-1) return dp[i][j];
        
        int ans = max(maxSum(i+1,j,nums,k-1,sum+nums[i],dp),maxSum(i,j-1,nums,k-1,sum+nums[j],dp));
        
        return dp[i][j] = ans;
    }
    int solve(vector<int>& nums,int k){
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return maxSum(0,nums.size()-1,nums,k,0,dp);
        
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.solve(nums,k);
    cout<<ans;
    return 0;
}