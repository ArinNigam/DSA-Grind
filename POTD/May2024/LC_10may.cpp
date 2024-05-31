// K-th Smallest Prime Fraction (Medium)
// Topic: Heap (Priority Queue)
// Expected Time Complexity: O(nlogn)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/k-th-smallest-prime-fraction/

// You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
// For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

// Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

// Example 1:
// Input: arr = [1,2,3,5], k = 3
// Output: [2,5]
// Explanation: The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
// The third fraction is 2/5.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();

        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                pq.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution ob;
    auto ans = ob.kthSmallestPrimeFraction(nums, k);
    // cout<<ans;
    for (auto it : ans)
    {
        cout << it << ' ';
    }
    return 0;
}