// Convert an Array Into a 2D Array With Conditions (Medium)

// You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

// The 2D array should contain only the elements of the array nums.
// Each row in the 2D array contains distinct integers.
// The number of rows in the 2D array should be minimal.
// Return the resulting array. If there are multiple answers, return any of them.

// Note that the 2D array can have a different number of elements on each row.

// Input: nums = [1,3,4,1,2,3,1]
// Output: [[1,3,4,2],[1,3],[1]]
// Explanation: We can create a 2D array that contains the following rows:
// - 1,3,4,2
// - 1,3
// - 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>ans;
        map<int,int>mp;
        int maxi = 0;
        for (int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi = max(maxi,mp[nums[i]]);
        }
        for (int i=0;i<maxi;i++){
            vector<int> temp;
            for (int j=0;j<n;j++){
                if (find(temp.begin(),temp.end(),nums[j])==temp.end() && mp[nums[j]]!=0){
                    temp.push_back(nums[j]);
                    mp[nums[j]]--;
                }
            }
            ans.push_back(temp);
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
    auto ans = ob.findMatrix(nums);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}