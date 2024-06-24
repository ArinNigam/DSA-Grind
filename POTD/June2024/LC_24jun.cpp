// Minimum Number of K Consecutive Bit Flips (Hard)

// You are given a binary array nums and an integer k.
// A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
// Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.
// A subarray is a contiguous part of an array.

// Input: nums = [0,0,0,1,0,1,1,0], k = 3
// Output: 3
// Explanation: 
// Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
// Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
// Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> flipped(n,0);
        int ans = 0;
        int cntFlips = 0;
        
        for (int i=0;i<n;i++){
            if (i>=k){
                if (flipped[i-k]==1){
                    cntFlips--;
                }
            }
            
            if ((cntFlips%2 == 1 && nums[i]==1)|| (cntFlips%2 == 0 && nums[i]==0)){
                if (i+k > n){
                    return -1;
                }
                
                cntFlips++;
                flipped[i] = 1;
                ans++;
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
    int k;
    cin>>k;
    Solution ob;
    auto ans = ob.minKBitFlips(nums,k);
    cout<<ans;
    return 0;
}