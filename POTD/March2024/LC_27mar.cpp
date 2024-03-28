#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        int cnt = 0;
        int left = 0, right = 0;
        while(right<n){
            prod*= nums[right++];
            while(left<=right && prod>=k){
                prod = prod/nums[left++];
            }
            cnt += right-left+1;
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
    auto ans = ob.numSubarrayProductLessThanK(nums,k);
    cout<<ans;
    return 0;
}