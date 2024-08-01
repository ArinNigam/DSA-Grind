// Reverse Substrings Between Each Pair of Parentheses (Medium)

// Topic: String
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.

// Input: s = "(abcd)"
// Output: "dcba"

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                string temp = "";
                while (!st.empty() && st.top() != '(')
                {
                    temp += st.top();
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
                for (int j = 0; j < temp.size(); j++)
                {
                    st.push(temp[j]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans;
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

signed main()
{
    string s;
    cin >> s;
    Solution ob;
    auto ans = ob.reverseParentheses(s);
    cout << ans;
    return 0;
}