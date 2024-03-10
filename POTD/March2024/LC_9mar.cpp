//Minimum Common Value (Easy)

// Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
// Input: nums1 = [1,2,3], nums2 = [2,4]
// Output: 2
// Explanation: The smallest element common to both arrays is 2, so we return 2.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0;
        int j = 0;
        
        while(i<n && j<m){
            if (nums1[i] > nums2[j]){
                 
                j++;
            }
            else if (nums1[i]<nums2[j]){
                i++;
            }
            else{
                return nums1[i];
            }
        }
        return -1;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<int>nums1(n);
    vector<int>nums2(m);
    for (int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for (int i=0;i<n;i++){
        cin>>nums2[i];
    }
    Solution ob;
    auto ans = ob.getCommon(nums1,nums2);
    cout<<ans;
    return 0;
}