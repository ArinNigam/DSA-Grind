// XOR Queries of a Subarray (Medium)

// You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].
// For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).
// Return an array answer where answer[i] is the answer to the ith query.

// Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
// Output: [2,7,14,8] 
#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    int seg[4*100005];
    void build(int ind,int low,int high,vector<int>&nums){
        if (low == high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);
        seg[ind] = seg[2*ind+1]^seg[2*ind+2];
    }
    int query(int ind,int low,int high,int l,int r){
        if (low >= l && high<=r){
            return seg[ind];
        }
        if (l > high || r < low){
            return 0;
        }

        int mid = (low + high)/2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return left ^ right;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree st;
        int n = nums.size();
        st.build(0,0,n-1,nums);
        vector<int>ans;
        for(auto it:queries){
            int l = it[0];
            int r = it[1];
            int res = st.query(0,0,n-1,l,r);
            ans.push_back(res);
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
    int m;
    cin>>m;
    vector<vector<int>>queries(m,vector<int>(2));
    for(int i=0;i<m;i++){
        cin>>queries[i][0] >> queries[i][1];
    }
    Solution ob;
    auto ans = ob.xorQueries(nums,queries);
    for(auto it:ans){
        cout << it <<' ';
    }
    return 0;
}