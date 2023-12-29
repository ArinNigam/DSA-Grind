// Fruits and Baskets

// INPUT
// 4 
// 1 1 2 3

// OUTPUT
// 3

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        unordered_map<int,int>mp;
        int maxi = 0;
        int l = 0;
        int r = 0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>2){
                mp[nums[l]]--;
                if (mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
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
    int ans = ob.solve(nums);
    cout<<ans;
    return 0;
}


