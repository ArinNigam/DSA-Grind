// Sort Array by Increasing Frequency (Easy)

// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
// Return the sorted array.

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        if (p1.second == p2.second){
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        vector<pair<int,int>>vp(201,pair<int,int>(0,0));
        for(int i=0;i<nums.size();i++){
            vp[nums[i]+100].first = nums[i];
            vp[nums[i]+100].second++;
        }
        sort(vp.begin(),vp.end(),cmp);

        for(auto it:vp){
            if (it.second == 0) continue;
            for(int i=0;i<it.second;i++){
                ans.push_back(it.first);
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
    auto ans = ob.frequencySort(nums);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}