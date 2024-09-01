// 2 Keys Keyboard (Medium)
// There is only one character 'A' on the screen of a notepad. You can perform two operations on this notepad for each step:
// Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
// Paste: You can paste the characters which are copied the last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

// Example 1:
// Input: n = 3
// Output: 3

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        int cnt = 0;
        int fact = 2;
        while (n > 1)
        {
            while (n % fact == 0)
            {
                cnt += fact;
                n /= fact;
            }
            fact++;
        }
        return cnt;
    }
};
signed main()
{
    int n;
    cin >> n;

    Solution ob;
    auto ans = ob.minSteps(n);
    cout << ans;
    return 0;
}