// Append Characters to String to Make Subsequence (Medium)
// Topic: Strings
// Expected Time Complexcity: O(N)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

// You are given two strings s and t consisting of only lowercase English letters.
// Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

// Example 1:
// Input: s = "coaching", t = "coding"
// Output: 4
// Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
// Now, t is a subsequence of s ("coachingding").
// It can be shown that appending any 3 characters to the end of s will never make t a subsequence.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        int i = 0;
        int j = 0;

        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                j++;
            }
            i++;
        }
        return m - j;
    }
};

signed main()
{
    string s, t;
    cin >> s >> t;
    Solution ob;
    auto ans = ob.appendCharacters(s, t);
    cout << ans;
    return 0;
}