// Maximum Score From Removing Substrings (Medium)

// Topic: String
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/maximum-score-from-removing-substrings/

// You are given a string s and two integers x and y. You can perform two types of operations any number of times.

// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        stack<char> st;
        int n = s.length();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (x > y)
            {
                if (s[i] == 'b')
                {
                    if (!st.empty() && st.top() == 'a')
                    {
                        sum += x;
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else
            {
                if (s[i] == 'a')
                {
                    if (!st.empty() && st.top() == 'b')
                    {
                        sum += y;
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        string t = "";
        while (!st.empty())
        {
            t += st.top();
            st.pop();
        }
        reverse(t.begin(), t.end());

        for (int i = 0; i < t.size(); i++)
        {
            if (x > y)
            {
                if (t[i] == 'a')
                {
                    if (!st.empty() && st.top() == 'b')
                    {
                        sum += y;
                        st.pop();
                    }
                    else
                    {
                        st.push(t[i]);
                    }
                }
                else
                {
                    st.push(t[i]);
                }
            }
            else
            {
                if (t[i] == 'b')
                {
                    if (!st.empty() && st.top() == 'a')
                    {
                        sum += x;
                        st.pop();
                    }
                    else
                    {
                        st.push(t[i]);
                    }
                }
                else
                {
                    st.push(t[i]);
                }
            }
        }
        return sum;
    }
};

signed main()
{
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    Solution ob;
    auto ans = ob.maximumGain(s, x, y);
    cout << ans;
    return 0;
}