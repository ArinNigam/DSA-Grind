// Permutations (Medium)
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(vector<int> &temp, vector<int>& nums, vector<vector<int>>& ans, int freq[]){
      if (temp.size() == nums.size()){
        ans.push_back(temp);
        return;
      }
      for (int i =0;i<nums.size();i++){
        if (!freq[i]){
          temp.push_back(nums[i]);
          freq[i]=1;
          func(temp,nums,ans,freq);
          freq[i]=0;
          temp.pop_back();
        }
      }
    }  
    vector<vector<int>> permute(vector<int>& nums) { 
        vector < vector < int >> ans;
        vector < int > temp;
        int n = nums.size();
        int freq[n];
        for (int i=0;i<n;i++){
            freq[i]=0;
        }
        func(temp,nums,ans,freq);
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
    auto ans = ob.permute(nums);
    
    return 0;
}