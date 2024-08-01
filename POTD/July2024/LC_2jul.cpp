// Intersection of Two Arrays II (Easy)

// Topic: Array
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : nums1)
        {
            mp[num]++;
        }
        for (auto num : nums2)
        {
            mp[num]--;
            if (mp[num] >= 0)
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }
    Solution ob;
    auto ans = ob.intersect(nums1, nums2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}