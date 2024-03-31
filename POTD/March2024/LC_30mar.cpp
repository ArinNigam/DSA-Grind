//  Subarrays with K Different Integers (Hard)

// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.
// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n = nums.size();
        int left = 0,right = 0;
        unordered_map<int,int>mp;
        int cnt = 0;
        while(right<n){
            if (mp[nums[right]]++==0){
                k--;
            }
            while(k<0){
                if (--mp[nums[left]]==0){
                    k++;
                }
                left++;
            }
            cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
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
    auto ans = ob.subarraysWithKDistinct(nums,k);
    cout<<ans;
    return 0;
}