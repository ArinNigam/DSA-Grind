// Minimum number of operation to make array continuous
// All elements in nums are unique.
// the difference between the maximum element and the minimum element in nums equals nums.length - 1.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int ans = n;
        unordered_set<int>st;
        for (auto i:nums){
            st.insert(i);
        }
        vector<int>unique(st.begin(),st.end());
        sort(unique.begin(),unique.end());
        int j = 0;
        int m = unique.size();
        for (int i=0;i<m;i++){
            while(j<m && unique[j] < unique[i] + n){
                j++;
            }
            ans = min(ans,n-j+i);
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
    auto ans = ob.minOperations(nums);
    cout<<ans;
    return 0;
}