// Sort an Array (Medium)

// Topic: Sorting
// Expected Time Complexity: O(nlogn)
// Expected Space Complexity: O(1)
// URL: https://leetcode.com/problems/sort-an-array/

// Given an array of integers nums, sort the array in ascending order and return it.
// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPivot(int l, int r, vector<int> &nums)
    {
        int i = l, j = r;
        int p = nums[l];
        while (i < j)
        {
            while (nums[i] <= p && i < r)
            {
                i++;
            }
            while (nums[j] > p && j > l)
            {
                j--;
            }
            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[l], nums[j]);
        return j;
    }
    void quickSort(int l, int r, vector<int> &nums)
    {
        if (l < r)
        {
            int p = findPivot(l, r, nums);
            quickSort(l, p - 1, nums);
            quickSort(p + 1, r, nums);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        quickSort(0, n - 1, nums);
        return nums;
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
    auto ans = ob.sortArray(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}