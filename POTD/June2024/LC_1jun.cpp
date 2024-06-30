// Score of a String (Easy)
// Topic: Strings
// Expected Time Complexcity: O(N)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/score-of-a-string/

// You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
// Return the score of s.

// Input: s = "hello"
// Output: 13
// Explanation:
// The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int cnt = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            cnt += abs(s[i + 1] - s[i]);
        }
        return cnt;
    }
};

signed main()
{
    string s;
    cin >> s;
    Solution ob;
    auto ans = ob.scoreOfString(s);
    cout << ans;
    return 0;
}