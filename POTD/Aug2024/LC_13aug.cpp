// Combination Sum II (Medium)

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
 
    void solve(int i,int sum,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        int n = nums.size();
        if (sum == 0){
            
            ans.push_back(temp);
        }
        for(int j = i;j<n;j++){
            if (j > i && nums[j] == nums[j-1]) continue;
            if (nums[i] > sum) break;
            temp.push_back(nums[j]);
            solve(j+1,sum-nums[j],nums,temp,ans);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
       
        solve(0,target,nums,temp,ans);
        
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
  auto ans = ob.combinationSum2(nums,k);
  cout<<ans;
  return 0;
}