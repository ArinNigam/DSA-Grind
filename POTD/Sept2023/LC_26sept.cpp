// remove Duplicate letters 
// Create a lexographially smallest string possible
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        unordered_map<char,bool>check;
        int n = s.size();
        for (int i = 0;i<n;i++){
            mp[s[i]]++;
        }
        stack<char>st;
        
        for (int i=0;i<n;i++){
            char temp = s[i];
            if (check[temp]){
                mp[temp]--;
                continue;
            }
            while(!st.empty() && temp<st.top() && mp[st.top()] > 1){
                mp[st.top()]--;
                check[st.top()] = false;
                st.pop();
            }
            st.push(temp);
            check[temp] = true;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

signed main()
{    
    string s;
    cin>>s;
    
    Solution ob;
    auto ans = ob.removeDuplicateLetters(s);
    cout<<ans;
    return 0;
}