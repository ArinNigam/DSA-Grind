// Sum of All Subset XOR Totals (Easy)
// Topic: Bit Manipulation
// Expected Time Complexity: O(2^n)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

// The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

// For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// Given an array nums, return the sum of all XOR totals for every subset of nums.

// Note: Subsets with the same elements should be counted multiple times.

// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

// Input: nums = [1,3]
// Output: 6
// Explanation: The 4 subsets of [1,3] are:
// - The empty subset has an XOR total of 0.
// - [1] has an XOR total of 1.
// - [3] has an XOR total of 3.
// - [1,3] has an XOR total of 1 XOR 3 = 2.
// 0 + 1 + 3 + 2 = 6

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int i = 0;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            int subset_sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    subset_sum ^= nums[j];
                }
            }
            sum += subset_sum;
        }
        return sum;
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
    Solution ob;
    auto ans = ob.subsetXORSum(nums);
    cout << ans;
    return 0;
}