// Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (Medium)
// Topic: Arrays & Deque
// Expected Time Complexcity: O(N)
// Expected Space Complexity: O(N)
// Problem Statement: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

// Example 1:
// Input: nums = [8,2,4,7], limit = 4
// Output: 2
// Explanation: All subarrays are:
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4.
// Therefore, the size of the longest subarray is 2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int i = 0, j = 0;
        int n = nums.size();

        deque<int> inc, dec;
        int sz = 0;
        while (j < n)
        {
            while (!inc.empty() && nums[j] < inc.back())
            {
                inc.pop_back();
            }
            inc.push_back(nums[j]);

            while (!dec.empty() && nums[j] > dec.back())
            {
                dec.pop_back();
            }
            dec.push_back(nums[j]);

            while (dec.front() - inc.front() > limit)
            {
                if (nums[i] == dec.front())
                {
                    dec.pop_front();
                }
                if (nums[i] == inc.front())
                {
                    inc.pop_front();
                }
                i++;
            }

            sz = max(sz, j - i + 1);

            j++;
        }
        return sz;
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
    auto ans = ob.longestSubarray(nums, k);
    cout << ans;
    return 0;
}