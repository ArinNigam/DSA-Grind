//Binary Subarrays With Sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n = nums.size();
        int l = 0;
        int r = 0;
        int len = 0;
        int cnt = 0;
        while(r<n){
            len+=nums[r];
            while(len>k && l<=r){
                len-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
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
    int ans = ob.numSubarraysWithSum(nums,k);
    cout<<ans;
    return 0;
}