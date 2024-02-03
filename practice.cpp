#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int solve(int ind,int k,vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        if (ind>=n){
            return 0;
        }
        if (dp[ind]!=-1){
            return dp[ind];
        }
        int mx = 0,ans =0;
        for (int i=ind;i<min(ind+k,n);i++){
            mx = max(mx,nums[i]);
            ans = max(ans,(i-ind+1)*mx + solve(i+1,k,nums,dp));
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
        return solve(0,k,arr,dp);
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
    auto ans = ob.maxSumAfterPartitioning(nums,k);
    cout<<ans;
    return 0;
}