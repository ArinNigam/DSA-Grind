//constrained Subset Sum
// Input: nums = [10,2,-10,5,20], k = 2
// Output: 37
// Explanation: The subsequence is [10, 2, 5, 20].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = nums[0];
        int ans = nums[0];
        priority_queue<pair<int,int>>pq;
        pq.push({dp[0],0});
        for (int i=1;i<n;i++){
            while(!pq.empty()){
                auto x = pq.top();
                if (i-x.second>k){
                    pq.pop();
                }
                else{
                    break;
                }
            }
            dp[i] = max(nums[i],nums[i] + pq.top().first);
            ans = max(ans,dp[i]);
            pq.push({dp[i],i});
        }
        return ans;
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
    auto ans = ob.constrainedSubsetSum(nums,k);
    cout<<ans;
    return 0;
}