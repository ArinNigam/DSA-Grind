// Find All Duplicates in an Array (Medium)
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        map<int,int>mp;
        for (int i=0;i<n;i++){
            if (mp.find(nums[i])!=mp.end()){
                ans.push_back(nums[i]);
            }
            mp[nums[i]]++;
        }
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
    auto ans = ob.findDuplicate(nums);
    cout<<ans;
    return 0;
}