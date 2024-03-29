// Count Subarrays Where Max Element Appears at Least K Times (Medium)

// You are given an integer array nums and a positive integer k.
// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
// A subarray is a contiguous sequence of elements within an array.

// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        map<int,int>mp;
        long long cnt = 0;
        int left = 0,right = 0;
        while(right<n){
            mp[nums[right]]++;
            while(mp[maxi] >= k){
                cnt+= n-right;
                mp[nums[left++]]--;
            }
            right++;
        }
        return cnt;
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
    auto ans = ob.countSubarrays(nums,k);
    cout<<ans;
    return 0;
}