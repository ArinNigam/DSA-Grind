// Subsets (Easy)

// Given an integer array nums of unique elements, return all possible 
// subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if (ind<0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind-1,nums,temp,ans);
        temp.pop_back();
        
        solve(ind-1,nums,temp,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        solve(n-1,nums,temp,ans);
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
    auto ans = ob.subsets(nums);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}