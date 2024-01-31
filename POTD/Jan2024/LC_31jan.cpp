//Daily Temperatures (Medium)
// Given an array of integers temperatures represents the daily temperatures, 
// return an array answer such that answer[i] is the number of days you have 
// to wait after the ith day to get a warmer temperature. If there is no future 
// day for which this is possible, keep answer[i] == 0 instead.

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// HINT:next greater element
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