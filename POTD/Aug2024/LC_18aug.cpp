// Ugly Number II (Medium)
// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.

// Example 1:
// Input: n = 10
// Output: 12

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;

        for (int i = 1; i < n; i++)
        {
            dp[i] = min({dp[p1] * 2, dp[p2] * 3, dp[p3] * 5});
            if (dp[i] == dp[p1] * 2)
            {
                p1++;
            }
            if (dp[i] == dp[p2] * 3)
            {
                p2++;
            }
            if (dp[i] == dp[p3] * 5)
            {
                p3++;
            }
        }
        return dp[n - 1];
    }
};
signed main()
{
    int n;
    cin >> n;

    Solution ob;
    auto ans = ob.nthUglyNumber(n);
    cout << ans;
    return 0;
}