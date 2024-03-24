// Find the Duplicate Number (Medium)
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.

// Input: nums = [1,3,4,2,2]
// Output: 2

// Input: nums = [3,1,3,4,2]
// Output: 3

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for (int i=0;i<n;i++){
            if (mp.find(nums[i])!=mp.end()){
                return nums[i];
            }
            mp[nums[i]]++;
        }
        return 0;
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
    auto ans = ob.findDuplicate(nums);
    cout<<ans;
    return 0;
}