//Subarray with k different integers
// INPUT
// 5 2
// 1 2 1 2 3
// OUTPUT
// 7

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>nums,int k){
        int n = nums.size();
        unordered_map<int,int>mp;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<n){
            if (!mp[nums[r]]++){
                k--;
            }
            for (auto i:mp){
                cout<<i.first<<" "<<i.second<<endl;
            }
            cout<<r<<endl;
            while(k<0){
                if(!--mp[nums[l]]){
                    k++;
                }
                l++;
            }
            ans+= r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
        
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
    int ans = ob.subarraysWithKDistinct(nums,k);
    cout<<ans;
    return 0;
}