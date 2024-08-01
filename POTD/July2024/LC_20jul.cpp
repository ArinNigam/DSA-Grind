// Lucky Numbers in a Matrix (Easy)

// Topic: Array
// Expected Time Complexity: O(m*n)
// Expected Space Complexity: O(1)
// URL: https://leetcode.com/problems/lucky-numbers-in-a-matrix/

// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
  {
    int n = rowSum.size();
    int m = colSum.size();
    int currR = 0;
    int currC = 0;
    vector<vector<int>> res(n, vector<int>(m, 0));
    while (currR < n || currC < m)
    {
      if (currR >= n)
      {
        res[n - 1][currC] = colSum[currC];
        currC++;
        continue;
      }
      else if (currC >= m)
      {
        res[currR][m - 1] = rowSum[currR];
        currR++;
        continue;
      }
      int val = min(rowSum[currR], colSum[currC]);
      rowSum[currR] -= val;
      colSum[currC] -= val;
      res[currR][currC] = val;

      if (rowSum[currR] == 0)
      {
        currR++;
      }
      if (colSum[currC] == 0)
      {
        currC++;
      }
    }
    return res;
  }
};
signed main()
{
  int n;
  cin >> n;
  vector<int> rowSum(n);
  for (int i = 0; i < n; i++)
  {
    cin >> rowSum[i];
  }
  vector<int> colSum(n);
  for (int i = 0; i < n; i++)
  {
    cin >> colSum[i];
  }
  Solution ob;
  auto ans = ob.restoreMatrix(rowSum, colSum);
  for (auto it : ans)
  {
    for (auto j : it)
    {
      cout << j << " ";
    }
  }
  return 0;
}