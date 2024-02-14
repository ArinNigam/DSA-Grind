//  Rearrange Array Elements by Sign (Medium)

// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// 1. Every consecutive pair of integers have opposite signs.
// 2. For all integers with the same sign, the order in which they were present in nums is preserved.
// 3. The rearranged array begins with a positive integer.
// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int even = 0;
        int odd = 1;
        for (int i=0;i<n;i++){
            if (nums[i]>0){
                ans[even] = nums[i];
                even+=2;
            }
            else{
                ans[odd] = nums[i];
                odd+=2;
            }
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
    auto ans = ob.rearrangeArray(nums);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}