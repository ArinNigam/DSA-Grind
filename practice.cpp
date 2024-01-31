#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        for (int i=n-1;i>=0;i--){
            while (!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if (!st.empty()){
                ans[i] = st.top()-i;
            }
            st.push(i);
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
    auto ans = ob.dailyTemperatures(nums);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}