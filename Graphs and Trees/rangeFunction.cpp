// Range Function

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int seg[4*100005];
    void build(int ind,int low,int high,vector<int>&nums){
        if (low==high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*ind + 1,low,mid,nums);
        build(2*ind + 2,mid+1,high,nums);
        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }
    int query(int ind,int low,int high,int l,int r){
        if (low>=l && high<=r){
            return seg[ind];
        }
        if (high < l || low > r){
            return 0;
        }
        
        int mid = (low+high)/2;
        int left = query(2*ind + 1,low,mid,l,r);
        int right = query(2*ind + 2,mid+1,high,l,r);
        return left + right;
    }
    void clear(){
        memset(seg,0,sizeof(seg));
    }
    vector<int> solve(int n,vector<int>& nums,vector<vector<int>>&queries){
        build(0,0,n-1,nums);
        vector<int> ans;
        int m = queries.size();
        for(int i=0;i<m;i++){
            if (queries[i][0]==1){
                int j = queries[i][1]-1;
                int val = queries[i][2];
                nums[j] = val;
                clear();
                build(0,0,n-1,nums);
                
            }
            else if(queries[i][0]==2){
                int l = queries[i][1]-1;
                int r = queries[i][2]-1;
                int sum = 0;
                for(int i=l;i<=r;i++){
                    for(int j=i;j<=r;j++){
                        if (j>i) continue;
                        sum += query(0,0,n-1,l,r);
                        
                    }
                }
                ans.push_back(sum);
            }
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
    vector<vector<int>>queries(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>queries[i][0];
        cin>>queries[i][1];
        cin>>queries[i][2];
    }
    
    Solution ob;
    auto ans = ob.solve(n,nums,queries);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}