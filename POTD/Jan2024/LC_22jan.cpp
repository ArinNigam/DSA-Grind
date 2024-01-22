// Set Mismatch (Easy)
// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
// You are given an integer array nums representing the data status of this set after the error.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+1,0);
        for (int i=0;i<n;i++){
            temp[nums[i]]++;
        }
        vector<int>ans(2,0);
        for (int i=1;i<=n;i++){
            if (temp[i]==2){
                ans[0]=i;
            }
            if (temp[i]==0){
                ans[1]=i;
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
    auto ans = ob.findErrorNums(nums);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}