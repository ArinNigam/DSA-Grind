#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans = INT_MIN;
        int ele = 0;
        for (auto it:mp){
            if (it.second>ans){
                ans = it.second;
                ele = it.first;
            }
        }
        return ele;
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
    auto ans = ob.majorityElement(nums);
    cout<<ans;
    return 0;
}