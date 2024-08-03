// Range Sum of Sorted Subarray Sums (Medium)

// You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
// Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

// Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
// Output: 13 
// Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    const int mod = 1e9 + 7;
    int seg[4*1000005];
    void build(int ind,int low,int high,vector<int>&nums){
        if (low == high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);
        seg[ind] = (seg[2*ind+1]% mod + seg[2*ind+2] % mod)%mod;
    }
    int query(int ind,int low,int high,int l,int r){
        if (low >= l && high <= r){
            return seg[ind];
        }
        if (high < l || low > r){
            return 0;
        }
        int mid = (low + high)/2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return seg[ind] = (left%mod + right%mod)%mod;
    }
};
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>temp;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(),temp.end());
        SegmentTree st;
        st.build(0,0,temp.size()-1,temp);
        return st.query(0,0,temp.size()-1,left-1,right-1);
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
    int left,right;
    cin>>left>>right;
    Solution ob;
    auto ans = ob.rangeSum(nums,n,left,right);
    cout<<ans;
    return 0;
}