// Contiguous Array (Medium)
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum = 0;
        int sub_array = 0;
        for (int i=0;i<n;i++){
            sum+=nums[i]==0 ? -1 : 1;
            if (sum == 0){
                sub_array = i+1;
            }
            else if(mp.find(sum)!=mp.end()){
                sub_array = max(sub_array,i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return sub_array;
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
    auto ans = ob.findMaxLength(nums);
    cout<<ans;
    return 0;
}