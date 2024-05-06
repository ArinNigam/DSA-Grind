// Largest Positive Integer That Exists With Its Negative (Easy)

// Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

// Return the positive integer k. If there is no such integer, return -1.

// Example 1:

// Input: nums = [-1,2,-3,3]
// Output: 3
// Explanation: 3 is the only valid k we can find in the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        int find = -1;
        while(i<n && nums[i]<0){
            if (abs(nums[i]) < nums[j]){
                j--;
            }
            else if ( abs(nums[i]) == nums[j]){
                find = nums[j];
                break;
            }
            else{
                i++;
            }
            
        }
        return find;
    }
};
// -7 -1 1 6 7 10
signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.findMaxK(nums);
    cout<<ans;
    return 0;
}