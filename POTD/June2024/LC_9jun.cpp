// Subarray Sums Divisible by K (Medium)
// Topic: Arrays
// Expected Time Complexcity: O(N)
// Expected Space Complexity: O(N)
// Problem Statement: https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int cnt = 0;

        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int mod = sum % k;
            if (mod < 0)
            {
                mod += k;
            }
            if (mp.find(mod) == mp.end())
            {
                mp[mod] = 1;
            }
            else
            {
                cnt += mp[mod];
                mp[mod]++;
            }
        }
        return cnt;
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
    auto ans = ob.subarraysDivByK(nums, k);
    cout << ans;
    return 0;
}