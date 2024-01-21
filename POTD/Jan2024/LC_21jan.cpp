// House Robber (Easy)
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// condition: points can't be adjacent

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int ind,vector<int>&nums,vector<int>&dp){
        if (ind<0){
            return 0;
        }
        if (dp[ind]!=-1){
            return dp[ind];
        }
        int pick = nums[ind] + func(ind-2,nums,dp);
    
        int notPick = func(ind-1,nums,dp);
        return dp[ind] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return func(n-1,nums,dp);
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
    auto ans = ob.rob(nums);
    cout<<ans;
    return 0;
}