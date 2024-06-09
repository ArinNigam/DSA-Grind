// Continuous Subarray Sum (Medium)

// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

// A good subarray is a subarray where:
// its length is at least two, and
// the sum of the elements of the subarray is a multiple of k.
// Note that:

// A subarray is a contiguous part of the array.
// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

// Example 1:
// Input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==1) return false;
        
        unordered_map<int,int>mp;
        int prefix = 0;
        mp[0] = -1;
        int sum = 0;
        for (int i=0;i<n;i++){
            sum+=nums[i];
            sum%=k;
            if (mp.find(sum)!=mp.end()){
                if (i > mp[sum] + 1){
                    return true;
                }
            }
            else{
                mp[sum] = i;
            }
            
        }
        return false;
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
    int k;
    cin>>k;
    Solution ob;
    auto ans = ob.checkSubarraySum(nums,k);
    cout<<ans;
    return 0;
}