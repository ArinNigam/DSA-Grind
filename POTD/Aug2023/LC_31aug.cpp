//  Minimum Number of Taps to Open to Water a Garden
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mini = 1e9;
        vector<int>dp(n+1,1e9);
        dp[0] = 0;
        for (int i=0;i<=n;i++){
            int start = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);
            for (int j =start;j<=end;j++){
                dp[j] = min(dp[j],dp[start]+1);
            }
        }
        return dp[n]==1e9 ? -1 : dp[n];
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
    auto ans = ob.minTaps(n+1,nums);
    cout<<ans;
    return 0;
}