// Finding 132 pattern 
// nums[i]<nums[k]<nums[j]
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        int third = INT_MIN;
        for (int i=nums.size()-1;i>=0;i--){
            if(nums[i]<third){
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
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
    auto ans = ob.find132pattern(nums);
    cout<<ans;
    return 0;
}