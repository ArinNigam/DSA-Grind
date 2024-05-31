// Single Number III (Medium)
// Topic: Bit Manipulation
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/single-number-iii/

// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC- O(N) SC-O(N)
    vector<int> singleNumber1(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        vector<int> ans;
        for (auto it : mp)
        {
            if (it.second == 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }

    // TC-O(N) SC-O(N)
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorSum = 0;
        for (auto num : nums)
        {
            xorSum ^= num;
        }
        vector<int> ans(2, 0);
        int lowestBit = xorSum & -(unsigned int)xorSum;
        for (auto num : nums)
        {
            if ((lowestBit & num) == 0)
            {
                ans[0] ^= num;
            }
            else
            {
                ans[1] ^= num;
            }
        }
        return ans;
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
    auto ans = ob.singleNumber(nums);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}