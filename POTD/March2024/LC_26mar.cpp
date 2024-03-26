// First Missing Positive (Hard)
// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool flag = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==1){
                flag = 1;
            }
            if (nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }
        if (flag==0){
            return 1;
        }
        
        for(int i=0;i<n;i++){
            int val = abs(nums[i]);
            if (val==n){
                nums[0] = -abs(nums[0]);
            }
            else{
                nums[val] = -abs(nums[val]);
            }
        }
        
        for (int i=1;i<n;i++){
            if (nums[i] > 0){
                return i;
            }
        }
        
        if (nums[0] > 0){
            return n;
        }
        
        return n+1;
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
    auto ans = ob.firstMissingPositive(nums);
    cout<<ans;
    return 0;
}