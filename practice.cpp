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