// Make The String Great (Easy)
// Given a string s of lower and upper case English letters.

// A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

// 0 <= i <= s.length - 2
// s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
// To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
// Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

// Example 1:

// Input: s = "leEeetcode"
// Output: "leetcode"
// Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for (auto it:s){
            if (!st.empty() && abs(st.top()-it)==32){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        string ans="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.makeGood(s);
    cout<<ans;
    return 0;
}