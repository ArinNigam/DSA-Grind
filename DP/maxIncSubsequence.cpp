//Maximum sum increasing subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int solve(int ind,int prev_ind,vector<int>&nums,vector<vector<int>>&dp){
    int n = nums.size();
    if (ind==n) return 0;
    if (dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    int notTake = solve(ind+1,prev_ind,nums,dp);
    int take = 0;
    if (prev_ind==-1 || nums[ind]>nums[prev_ind]){
      take += nums[ind] + solve(ind+1,ind,nums,dp);
    }
    return dp[ind][prev_ind+1] = max(take,notTake);
  }
  int maxSumIS(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // return solve(0,-1,nums,dp);
    
    // Tabulation
    for (int i=n-1;i>=0;i--){
      for (int j=i-1;j>=-1;j--){
        int notTake = dp[i+1][j+1];
        int take = 0;
        if (j==-1 || nums[i]>nums[j]){
          take += nums[i] + dp[i+1][i+1];
        }
        dp[i][j+1] = max(take,notTake);
      }
    }
    return dp[0][0];
    
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
  int ans = ob.maxSumIS(nums);
  cout<<ans;
  return 0;
}