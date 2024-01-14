// Count Elements With Maximum Frequency (Easy)
// Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
// Input: nums = [1,2,2,3,1,4]
// Output: 4
// Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
// So the number of elements in the array with maximum frequency is 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        int maxi = 0;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxi = max(maxi,mp[nums[i]]);
        }
       
        int cnt = 0;
        for (auto it:mp){
            if (it.second==maxi){
                cnt+=it.second;
            }
        }
        return cnt;
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
    auto ans = ob.maxFrequencyElements(nums);
    cout<<ans;
    return 0;
}