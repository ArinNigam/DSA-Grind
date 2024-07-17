// Max Length Subarray
// 2 operations
// either chang a[i] to a[i] - 1 
// or change a[i] to 0
// You can perform the following two operations atmax x and y resp;

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxSubarray(int ind,int x,int y,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if (ind == nums.size()){
            return 0;
        }
        if (dp[ind][x][y]!=-1){
            return dp[ind][x][y];
        }
        int first = 0;
        if (x>=nums[ind]){
            first = 1 + findMaxSubarray(ind+1,x-nums[ind],y,nums,dp);
        }
        int second = 0;
        if (y>0){
            second = 1 + findMaxSubarray(ind+1,x,y-1,nums,dp);
        }
        return dp[ind][x][y] = max(first,second);
    }
    int solve(int x,int y,vector<int>& nums){
        int n = nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(x+1,vector<int>(y+1,-1)));
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(findMaxSubarray(i,x,y,nums,dp),maxi);
        }
        return maxi;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    int x,y;
    cin>>x>>y;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.solve(x,y,nums);
    cout<<ans;
    return 0;
}