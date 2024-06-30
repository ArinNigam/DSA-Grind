// Hand of Straights (Medium)
// Topic: Arrays
// Expected Time Complexcity: O(NlogN)
// Expected Space Complexity: O(N)
// Problem Statement: https://leetcode.com/problems/hand-of-straights/

// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
// Example 1:
// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find(vector<int> &hand, int k, int i)
    {
        int n = hand.size();
        int next = hand[i] + 1;
        hand[i] = -1;
        i++;
        int cnt = 1;
        while (i < n && cnt < k)
        {
            if (hand[i] == next)
            {
                next = hand[i] + 1;
                hand[i] = -1;
                cnt++;
            }
            i++;
        }
        return cnt == k;
    }
    bool isNStraightHand(vector<int> &hand, int k)
    {
        int n = hand.size();
        if (n % k)
        {
            return false;
        }
        sort(hand.begin(), hand.end());
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (hand[i] >= 0)
            {
                if (!find(hand, k, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    Solution ob;
    auto ans = ob.isNStraightHand(nums, k);
    cout << ans;
    return 0;
}