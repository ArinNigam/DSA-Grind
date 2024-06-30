// Minimum Number of Days to Make m Bouquets (Medium)
// Topic: Binary Search
// Expected Time Complexcity: O(NlogN)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

// Example 1:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int mid, int k, int m, vector<int> &bloomDay)
    {
        int n = bloomDay.size();
        int cnt = 0;
        int numOfBouquets = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            if (cnt == k)
            {
                numOfBouquets++;
                cnt = 0;
            }
        }
        return numOfBouquets >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if ((long long)m * k > n)
        {
            return -1;
        }
        int l = 1;
        int r = 1e9;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(mid, k, m, bloomDay))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

signed main()
{
    int n;
    cin >> n;
    int m, k;
    cin >> m >> k;
    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }
    Solution ob;
    auto ans = ob.minDays(bloomDay, m, k);
    cout << ans;
    return 0;
}