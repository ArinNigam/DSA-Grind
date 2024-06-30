// Grumpy Bookstore Owner (Medium)
// Topic: Arrays
// Expected Time Complexcity: O(N)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/grumpy-bookstore-owner/

// There is a bookstore owner that has a store open for n minutes.
// Every minute, some number of customers enter the store. You are
// given an integer array customers of length n where customers[i]
// is the number of the customer that enters the store at the start
// of the ith minute and all those customers leave after the end of
// that minute.

// On some minutes, the bookstore owner is grumpy. You are given a
// binary array grumpy where grumpy[i] is 1 if the bookstore owner is
//  grumpy during the ith minute, and is 0 otherwise.

// When the bookstore owner is grumpy, the customers of that minute
// are not satisfied, otherwise, they are satisfied.

// The bookstore owner knows a secret technique to keep themselves
// not grumpy for minutes consecutive minutes, but can only use it once.

// Return the maximum number of customers that can be satisfied throughout the day.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int initialSatisfaction = 0;
        int maxExtraSatisfaction = 0;
        int currentWindowSatisfaction = 0;

        for (int i = 0; i < customers.size(); ++i)
        {
            if (grumpy[i] == 0)
            {
                initialSatisfaction += customers[i];
            }
            else if (i < minutes)
            {
                currentWindowSatisfaction += customers[i];
            }
        }

        maxExtraSatisfaction = currentWindowSatisfaction;

        for (int i = minutes; i < customers.size(); ++i)
        {
            currentWindowSatisfaction += customers[i] * grumpy[i];
            currentWindowSatisfaction -= customers[i - minutes] * grumpy[i - minutes];
            maxExtraSatisfaction = max(maxExtraSatisfaction, currentWindowSatisfaction);
        }

        return initialSatisfaction + maxExtraSatisfaction;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<int> customers(n), grumpy(n);
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> grumpy[i];
    }
    int minutes;
    cin >> minutes;
    Solution ob;
    auto ans = ob.maxSatisfied(customers, grumpy, minutes);
    cout << ans;
    return 0;
}