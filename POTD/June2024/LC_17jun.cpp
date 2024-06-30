// Sum of Square Numbers ( Medium )
// Topic: Math
// Expected Time Complexcity: O(sqrt(N))
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/sum-of-square-numbers/

// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
// Example 1:

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int n)
    {
        for (int i = 2; i < sqrt(n); i++)
        {
            if (n % i != 0)
                continue;
            int expo = 0;
            while (n % i == 0)
            {
                n /= i;
                expo++;
            }
            if (i % 4 == 3 && expo % 2)
                return false;
        }
        return n % 4 != 3;
    }
};

signed main()
{
    int n;
    cin >> n;
    Solution ob;
    auto ans = ob.judgeSquareSum(n);
    cout << ans;
    return 0;
}