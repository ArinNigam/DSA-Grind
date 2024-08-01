// Minimum Deletions to Make String Balanced (Medium)

// Topic: String
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

// You are given a string s consisting only of characters 'a' and 'b'
// You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
// Return the minimum number of deletions needed to make s balanced.

// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        int cntB = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'a')
            {
                dp[i] = min(dp[i - 1] + 1, cntB);
            }
            else
            {
                dp[i] = dp[i - 1];
                cntB++;
            }
        }
        return dp[n];
    }
};
signed main()
{
    string s;
    Solution ob;
    auto ans = ob.minimumDeletions(s);
    cout << ans;
    return 0;
}