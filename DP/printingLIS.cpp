#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int curr,int prev,vector<int>&nums,vector<vector<int>>&dp){
        int n = nums.size();
        if (curr==n){
            return 0;
        }
        if (dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int take = 0;
        if (prev==-1 || nums[curr]>nums[prev]){
            take = 1 + solve(curr+1,curr,nums,dp);
        }
        int notTake = solve(curr+1,prev,nums,dp);
        return dp[curr][prev+1] = max(take,notTake);
    }
    vector<int> printingLongestIncreasingSubsequence(vector<int>& nums,int n){
        int maxi= 1;
        int lastIndex = 0;
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        for (int i=0;i<n;i++){
            hash[i] = i;
        }
        for(int i=0;i<n;i++){
            for (int prev=0;prev<i;prev++){
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    
                    dp[i] = max(dp[i],1 + dp[prev]);
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
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
    auto ans = ob.printingLongestIncreasingSubsequence(nums,n);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}