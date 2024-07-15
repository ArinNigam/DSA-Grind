// Segment Tree
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int seg[4* 100005];
    void build(int ind,int low,int high,vector<int>&nums){
        if (low==high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);
        seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
        
    }
    int query(int ind,int low,int high,int l,int r){
        if (low >= l && high<=r){
            return seg[ind];
        }
        if (high < l || low > r){
            return INT_MIN;
        }
        int mid = (low+high)/2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return max(left,right);
    }
    vector<int> segmentTree(vector<vector<int>>&queries,vector<int>& nums){
        int n = nums.size();
        build(0,0,n-1,nums);
        int m = queries.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int res = query(0,0,n-1,l,r);
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
    int q;
    cin>>q;
    vector<vector<int>>queries(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin>>queries[i][0]>>queries[i][1];
    }
    Solution ob;
    auto ans = ob.segmentTree(queries,nums);
    for(auto it:ans){
        cout<<it<<endl;
    }
    return 0;
}