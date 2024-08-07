// Longest Palindrome (Easy)
// Topic: Strings
// Expected Time Complexcity: O(N)
// Expected Space Complexity: O(N)
// Problem Statement: https://leetcode.com/problems/longest-palindrome/

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest
// palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

// Example 1:
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<int, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        int cnt = 0;
        int flag = 0;
        for (auto it : mp)
        {
            if (it.second % 2 == 0)
            {
                cnt += it.second;
            }
            else
            {
                cnt += it.second - 1;
                flag = 1;
            }
        }
        return cnt + flag;
    }
};

signed main()
{
    string s;
    cin >> s;
    Solution ob;
    auto ans = ob.longestPalindrome(s);
    cout << ans;
    return 0;
}