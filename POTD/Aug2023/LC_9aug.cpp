// Minimize the Maximum Difference of Pairs
// You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
// Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

// Input: nums = [10,1,2,7,1,3], p = 2
// Output: 1
// Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
// The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.

// Input: nums = [4,2,1,2], p = 1
// Output: 0
// Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFormMaxPairs(vector<int>&nums,int mid,int p){
        int cnt=0;
        int i=0;
        while(i<nums.size()-1 && cnt<p){
            if (nums[i+1]-nums[i] <= mid){
                 cnt++;
                 i+=2;
            }
            else{
                i++;
            }
        }
        return cnt==p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums[n-1]-nums[0];
        while(left<=right){
            int mid = (left+right)/2;
            if (canFormMaxPairs(nums,mid,p)){
                right = mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
signed main()
{    
    int n,p;
    cin>>n>>p;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.minimizeMax(nums,p);
    cout<<ans;
    return 0;
}