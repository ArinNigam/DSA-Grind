// Count Triplets That Can Form Two Arrays of Equal XOR (Medium)
// Topic: Array & Prefix XOR
// Expected Time Complexity: O(n^2)
// Expected Space Complexity: O(n)
// Problem Statement: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

// Given an array of integers arr.
// We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
// Let's define a and b as follows:

// a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// Note that ^ denotes the bitwise-xor operation.

// Return the number of triplets (i, j and k) Where a == b.

// Example 1:

// Input: arr = [2,3,1,6,7]
// Output: 4
// Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size() + 1;
        vector<int> pre(n, 0);
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (pre[i] == pre[j])
                {
                    cnt += j - i - 1;
                }
            }
        }
        return cnt;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.countTriplets(arr);
    cout << ans;
    return 0;
}