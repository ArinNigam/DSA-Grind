// Minimum Increment to Make Array Unique (Medium)
//  Topic: Arrays
//  Expected Time Complexcity: O(NlogN)
//  Expected Space Complexity: O(1)
//  Problem Statement: https://leetcode.com/problems/minimum-increment-to-make-array-unique/

//  You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
// Return the minimum number of moves to make every value in nums unique.
// The test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:
// Input: nums = [1,2,2]
// Output: 1
// Explanation: After 1 move, the array could be [1, 2, 3].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            num = max(num, nums[i]);
            cnt += num - nums[i];
            num++;
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
    Solution ob;
    auto ans = ob.minIncrementForUnique(nums);
    cout << ans;
    return 0;
}