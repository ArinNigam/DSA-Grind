// Minimum Difference Between Largest and Smallest Value in Three Moves (Medium)

// Topic: Array
// Expected Time Complexity: O(NlogN)
// Expected Space Complexity: O(1)
// URL: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

// You are given an integer array nums.
// In one move, you can choose one element of nums and change it to any value.
// Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

// Input: nums = [5,3,2,4]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 2 to 3. nums becomes [5,3,3,4].
// In the second move, change 4 to 3. nums becomes [5,3,3,3].
// In the third move, change 5 to 3. nums becomes [3,3,3,3].
// After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 3)
            return 0;

        int mini = INT_MAX;
        for (int i = n - 1; i >= n - 4; i--)
        {
            mini = min(mini, nums[i] - nums[i - n + 4]);
        }
        return mini;
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
    auto ans = ob.minDifference(nums);
    cout << ans;
    return 0;
}