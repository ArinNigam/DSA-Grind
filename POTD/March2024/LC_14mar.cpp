//Binary Subarrays With Sum (Medium)

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int curr = 0;
        int cnt = 0;
        for (auto num:nums){
            curr+=num;
            if (mp.find(curr-goal)!=mp.end()){
                cnt+=mp[curr-goal];
            }
            mp[curr]++;
        }
        return cnt;
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.numSubarraysWithSum(nums,k);
    cout<<ans;
    return 0;
}