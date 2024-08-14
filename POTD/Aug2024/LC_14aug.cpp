// Find K-th Smallest Pair Distance (Hard)

// The distance of a pair of integers a and b is defined as the absolute difference between a and b.
// Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

// Input: nums = [1,3,1], k = 1
// Output: 0
// Explanation: Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int mid,int k,vector<int>&nums){
        int n = nums.size();
        int cnt = 0;
        for(int i=0,j=1;j<n;j++){
            while(j > i && nums[j]-nums[i] > mid){
                i++;
            }
            cnt+=j-i;
        }
        return cnt < k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int l = 0;
        int r = nums[n-1];
        while (l<=r){
            int mid = (l + r)/2;
            if (isPossible(mid,k,nums)){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;
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
  int k;
  cin>>k;
  Solution ob;
  auto ans = ob.smallestDistancePair(nums,k);
  cout<<ans;
  return 0;
}