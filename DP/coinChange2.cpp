#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums,int sum){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        for (int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=sum;j++){
                if (j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for (auto i:dp){
          for (auto j:i){
            cout<<j<<" ";
          }
          cout<<endl;
        }
        return dp[n][sum];
    }
};

signed main()
{    
    int n,sum;
    cin>>n>>sum;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    int ans = ob.solve(nums,sum);
    cout<<ans;
    return 0;
}