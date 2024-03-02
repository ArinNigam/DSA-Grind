// Squares of a Sorted Array (Easy)
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
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
    auto ans = ob.sortedSquares(nums);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}