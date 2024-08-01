// Sort the Jumbled Numbers (Medium)

// Topic: Sorting
// Expected Time Complexity: O(NlogN)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/sort-the-jumbled-numbers/

// You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.
// The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.
// You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.
// Notes:
// Elements with the same mapped values should appear in the same relative order as in the input.
// The elements of nums should only be sorted based on their mapped values and not be replaced by them.

// Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
// Output: [338,38,991]
// Explanation:
// Map the number 991 as follows:
// 1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
// 2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
// Therefore, the mapped value of 991 is 669.
// 338 maps to 007, or 7 after removing the leading zeros.
// 38 maps to 07, which is also 7 after removing leading zeros.
// Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
// Thus, the sorted array is [338,38,991].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second < p2.second;
    }
    vector<int> sortJumbled(vector<int> &mp, vector<int> &nums)
    {
        vector<pair<int, int>> vp;
        for (auto num : nums)
        {
            int res = num;
            int x = 1;
            int ans = 0;
            if (num == 0)
            {
                ans = mp[num];
            }
            while (num > 0)
            {
                ans = mp[num % 10] * x + ans;
                x *= 10;
                num /= 10;
            }
            vp.push_back({res, ans});
        }
        cout << endl;
        sort(vp.begin(), vp.end(), cmp);
        vector<int> res;
        for (auto it : vp)
        {
            res.push_back({it.first});
        }
        return res;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<int> nums(n), mapping(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> mapping[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution ob;
    auto ans = ob.sortJumbled(mapping, nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}