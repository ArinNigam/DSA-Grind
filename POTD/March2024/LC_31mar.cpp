// Count Subarrays With Fixed Bounds (Hard)
// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.

// Return the number of fixed-bound subarrays.

// Example 1:

// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long cnt = 0;
        int lastInd = -1;
        int leftInd = -1,rightInd = -1;
        for (int i =0;i<n;i++){
            if (nums[i]==minK){
                leftInd=i;
            }
            if (nums[i]==maxK){
                rightInd=i;
            }
            if(!(nums[i]>= minK && nums[i]<=maxK)){ 
                lastInd=i;
            }
            cout<<leftInd<<" "<<rightInd<<" "<<lastInd<<" ";
            cnt+=max(0,min(leftInd,rightInd)-lastInd);
            cout<<cnt<<endl;
        }
        return cnt;
    }
};

signed main()
{    
    int n,minK,maxK;
    cin>>n>>minK>>maxK;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.countSubarrays(nums,minK,maxK);
    cout<<ans;
    return 0;
}