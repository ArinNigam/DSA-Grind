// Product of Array Except Self (Medium)
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n);
        int prefixProd = 1;
        for (int i=0;i<n;i++){
            prod[i] = prefixProd;
            prefixProd*=nums[i];
        }
        
        int suffixProd = 1;
        for (int i=n-1;i>=0;i--){
            prod[i]*= suffixProd;
            suffixProd*=nums[i];
        }
        return prod;
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
    auto ans = ob.productExceptSelf(nums);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}