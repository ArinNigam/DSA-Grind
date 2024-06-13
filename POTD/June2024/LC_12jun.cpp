// Sort Colors (Medium)

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>cnt(3,0);
        for (int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
        }
        
        int k = 0;
        for (int i=0;i<3;i++){
            for (int j=0;j<cnt[i];j++){
                nums[k++] = i;
            }
        }
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
    ob.sortColors(nums);
    for (auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}