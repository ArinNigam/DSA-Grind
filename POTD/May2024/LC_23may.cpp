// The Number of Beautiful Subsets (Medium)
//  Topic: Backtracking (Recursion)
//  Expected Time Complexity: O(2^n)
//  Expected Space Complexity: O(n)
//  Problem Statement: https://leetcode.com/problems/the-number-of-beautiful-subsets/

// You are given an array nums of positive integers and a positive integer k.
// A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
// Return the number of non-empty beautiful subsets of the array nums.
// A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

// Input: nums = [2,4,6], k = 2
// Output: 4
// Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
// It can be proved that there are only 4 beautiful subsets in the array [2,4,6].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int ind, int k, vector<int> &nums, unordered_map<int, int> &vis, int &cnt)
    {
        if (ind == nums.size())
        {
            cnt++;
            return;
        }

        if (vis.find(nums[ind] - k) == vis.end() && vis.find(nums[ind] + k) == vis.end())
        {
            vis[nums[ind]]++;
            solve(ind + 1, k, nums, vis, cnt);
            vis[nums[ind]]--;

            if (vis[nums[ind]] == 0)
            {
                vis.erase(nums[ind]);
            }
        }

        solve(ind + 1, k, nums, vis, cnt);
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> vis;
        solve(0, k, nums, vis, cnt);
        return cnt - 1;
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
    auto ans = ob.beautifulSubsets(nums, k);
    cout << ans;
    return 0;
}