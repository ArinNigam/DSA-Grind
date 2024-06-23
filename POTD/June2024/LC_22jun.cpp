// Count Number of Nice Subarrays (Medium)

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

// Example 1:
// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&nums,int k){
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;
        while(r<n){
            k-=nums[r]%2;
            while(k<0){
                k+=nums[l]%2;
                l++;
            }
            ans+= r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>customers(n),grumpy(n);
    for (int i=0;i<n;i++){
        cin>>customers[i];
    }
    for (int i=0;i<n;i++){
        cin>>grumpy[i];
    }
    int minutes;
    cin>>minutes;
    Solution ob;
    auto ans = ob.maxSatisfied(customers,grumpy,minutes);
    cout<<ans;
    return 0;
}