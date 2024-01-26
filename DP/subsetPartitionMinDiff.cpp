// Subset Partition with Minimum Difference
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        int max_sum = accumulate(nums.begin(), nums.end(),0);
        
        vector<vector<bool>>dp(n+1,vector<bool>(max_sum+1,false));
        for (int i=0;i<n;i++){
            dp[i][0] = true;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=max_sum;j++){
                if (j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int min_diff = INT_MAX;
        for (int i=0;i<=max_sum/2;i++){
            if (dp[n][i]){
                min_diff = min(min_diff,max_sum-2*i);
            }
        }
        return min_diff;
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
    int ans = ob.solve(nums);
    cout<<ans;
    return 0;
}