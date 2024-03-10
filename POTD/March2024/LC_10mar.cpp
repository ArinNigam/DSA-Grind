// Intersection of Two Arrays (Easy)

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int>st;
        for (auto it:nums1){
            st.insert(it);
        }
        for (int i=0;i<nums2.size();i++){
            if (st.find(nums2[i])!=st.end()){
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }
        return ans;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<int>nums1(n),nums2(m);
    for (int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for (int i=0;i<m;i++){
        cin>>nums2[i];
    }
    Solution ob;
    auto ans = ob.intersection(nums1,nums2);
    for (auto i:ans){
        cout<<i;
    }
    return 0;
}