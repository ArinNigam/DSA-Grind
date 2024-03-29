// Subarray Product Less Than K (Medium)
// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        int cnt = 0;
        int left = 0, right = 0;
        while(right<n){
            prod*= nums[right++];
            while(left<=right && prod>=k){
                prod = prod/nums[left++];
            }
            cnt += right-left+1;
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
    auto ans = ob.numSubarrayProductLessThanK(nums,k);
    cout<<ans;
    return 0;
}