// Longest Subarray With Maximum Bitwise AND (Medium)

// You are given an integer array nums of size n.
// Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
// In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
// Return the length of the longest such subarray.

// The bitwise AND of an array is the bitwise AND of all the numbers in it.
// A subarray is a contiguous sequence of elements within an array.

// Input: nums = [1,2,3,3,2,2]
// Output: 2
// Explanation:
// The maximum possible bitwise AND of a subarray is 3.
// The longest subarray with that value is [3,3], so we return 2.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        map<int,int>mp;
        int maxi = nums[n-1];
        for(int i=0;i<n-1;i++){
            if (nums[i] == nums[i+1]){
                cnt++;
            }
            else{
                mp[nums[i]] = max(mp[nums[i]],cnt);
                cnt = 1; 
            }
            maxi = max(maxi,nums[i]);
        }
        mp[nums[n-1]] = max(mp[nums[n-1]],cnt);
        return mp[maxi];
       
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
    auto ans = ob.longestSubarray(nums);
    cout<<ans;
    return 0;
}