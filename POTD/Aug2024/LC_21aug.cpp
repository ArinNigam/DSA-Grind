// Strange Printer (Hard)
// There is a strange printer with the following two special properties :
// The printer can only print a sequence of the same character each time.At each turn,
// the printer can print new characters starting from and ending at any place and will cover the original existing characters.Given a string s, return the minimum number of turns the printer needed to print it.

// Input: s = "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, string s, vector<vector<int>> &dp)
    {
        if (i == j)
        {
            return dp[i][j] = 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans;
        if (s[i] == s[j] || s[j - 1] == s[j])
        {
            ans = solve(i, j - 1, s, dp);
        }
        else if (s[i] == s[i + 1])
        {
            ans = solve(i + 1, j, s, dp);
        }
        else
        {
            ans = solve(i, j - 1, s, dp) + 1;
            for (int k = i + 1; k < j; k++)
            {
                if (s[k] == s[j])
                {
                    ans = min(ans, solve(i, k - 1, s, dp) + solve(k, j - 1, s, dp));
                }
            }
        }
        return dp[i][j] = ans;
    }
    int strangePrinter(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, s, dp);
    }
};
signed main()
{
    
    string s;
    cin >> s;
    Solution ob;
    auto ans = ob.strangePrinter(s);

    cout << ans;
    return 0;
}