#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>left(n,-1),right(n,n);
        for (int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if (!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for (int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if (!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }
        
        long long ans = 0;
        for (int i=0;i<n;i++){
            ans+=((long long)(i-left[i])*(right[i]-i)*nums[i])%mod;
            ans%=mod;
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
    auto ans = ob.sumSubarrayMins(nums);
    cout<<ans;
    return 0;
}