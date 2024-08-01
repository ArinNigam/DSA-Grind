// Three Consecutive Odds ( Easy )

// Topic: Array
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)
// URL: https://leetcode.com/problems/three-consecutive-odds/

// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 1)
            {
                if (arr[i - 2] % 2 && arr[i - 1] % 2 && arr[i] % 2)
                {
                    return true;
                }
            }
        }
        return false;
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
    auto ans = ob.threeConsecutiveOdds(nums);
    cout << ans;
    return 0;
}