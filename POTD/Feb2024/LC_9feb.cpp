// Largest Divisible Subset (Medium)
// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>hash(n);
        vector<int>dp(n+1,1);
        int maxi = 1;
        int last = 0;
        for (int i=1;i<n;i++){
            hash[i] = i;
            for (int j=0;j<i;j++){
               if (nums[i]%nums[j]==0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j; 
               }
            }
            if (dp[i] > maxi){
                maxi  = dp[i];
                last = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[last]);
        while(hash[last]!=last){
            last = hash[last];
            ans.push_back(nums[last]);
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
    auto ans = ob.largestDivisibleSubset(nums);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}