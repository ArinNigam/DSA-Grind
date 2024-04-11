// Remove K Digits (Medium)
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int>st;
        for (int i=0;i<n;i++){
            while (!st.empty() && k>0 && num[i] < st.top() ){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
       
        string ans;
        while(!st.empty()){
            if (k==0){
                ans+= st.top();
            }
            else{
                k--;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int cnt = 0;
        int m = ans.size();
        while(cnt<m && ans[cnt]=='0'){
            cnt++;
        }
        
        return ans.substr(cnt)=="" ? "0" : ans.substr(cnt);
    }
};

signed main()
{    
    int k;
    cin>>k;
    string nums;
    cin>>nums;
    Solution ob;
    auto ans = ob.removeKdigits(nums,k);
    cout<<ans;
    return 0;
}