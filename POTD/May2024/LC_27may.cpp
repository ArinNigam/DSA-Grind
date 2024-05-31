// Special Array With X Elements Greater Than or Equal X (Easy)
// Topic: Binary Search
// Expected Time Complexity: O(nlogn)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

// You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
// Notice that x does not have to be an element in nums.
// Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

// Input: nums = [3,5]
// Output: 2
// Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[n - 1] > n)
        {
            return n;
        }
        if (nums[0] == 0)
        {
            return -1;
        }
        int left = 0;
        int right = n - 1;
        int mid = 0;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > mid)
            {
                left = mid + 1;
            }
            else if (nums[mid] < mid)
            {
                right = mid - 1;
            }
            else
            {
                return -1;
            }
        }
        return nums[mid] > mid ? mid + 1 : mid;
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
    auto ans = ob.specialArray(nums);
    cout << ans;
    return 0;
}