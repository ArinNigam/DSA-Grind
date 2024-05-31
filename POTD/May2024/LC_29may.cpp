// Number of Steps to Reduce a Number in Binary Representation to One (Medium)
// Topic: Bit Manipulation
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
// If the current number is even, you have to divide it by 2.
// If the current number is odd, you have to add 1 to it.
// It is guaranteed that you can always reach one for all test cases.

// Input: s = "1101"
// Output: 6
// Explanation: "1101" corressponds to number 13 in their decimal representation.
// Step 1) 13 is odd, add 1 and obtain 14.
// Step 2) 14 is even, divide by 2 and obtain 7.
// Step 3) 7 is odd, add 1 and obtain 8.
// Step 4) 8 is even, divide by 2 and obtain 4.
// Step 5) 4 is even, divide by 2 and obtain 2.
// Step 6) 2 is even, divide by 2 and obtain 1.

#include <bits/stdc++.h>
    using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int n = s.size();
        int i = n - 1;
        int cnt = 0;
        int carry = 0;
        while (i)
        {
            if (s[i] - '0' + carry == 0)
            {
                carry = 0;
                cnt++;
            }
            else if (s[i] - '0' + carry == 2)
            {
                carry = 1;
                cnt++;
            }
            else
            {
                carry = 1;
                cnt += 2;
            }
            i--;
        }
        if (carry == 1)
        {
            cnt++;
        }
        return cnt;
    }
};

signed main()
{
    string s;
    cin >> s;
    Solution ob;
    auto ans = ob.numSteps(s);
    cout << ans << endl;
    return 0;
}