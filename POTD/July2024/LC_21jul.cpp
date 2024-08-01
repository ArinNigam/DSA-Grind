// Build a Matrix With Conditions (Hard)

// Topic: Graph
// Expected Time Complexity: O(k^2)
// Expected Space Complexity: O(k^2)
// URL: https://leetcode.com/problems/build-a-matrix-with-conditions/

// You are given a positive integer k. You are also given:
// a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
// a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
// The two arrays contain integers from 1 to k.
// You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.
// The matrix should also satisfy the following conditions:
// The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
// The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
// Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

// Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
// Output: [[3,0,0],[0,0,1],[0,2,0]]
// Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
// The row conditions are the following:
// - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
// - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
// The column conditions are the following:
// - Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
// - Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
// Note that there may be multiple correct answers.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int x, unordered_map<int, vector<int>> &adj, unordered_set<int> &vis, unordered_set<int> &currPath, vector<int> &ans)
    {
        if (currPath.count(x))
            return false;
        if (vis.count(x))
            return true;
        vis.insert(x);
        currPath.insert(x);

        for (auto it : adj[x])
        {
            if (!dfs(it, adj, vis, currPath, ans))
            {
                return false;
            }
        }
        currPath.erase(x);
        ans.push_back(x);
        return true;
    }
    vector<int> topoSort(unordered_map<int, vector<int>> &adj, int k)
    {
        unordered_set<int> vis;
        unordered_set<int> curr_path;
        vector<int> ans;
        for (int i = 1; i <= k; i++)
        {
            if (!dfs(i, adj, vis, curr_path, ans))
            {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        unordered_map<int, vector<int>> adj;
        for (auto edge : rowConditions)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> rowSort = topoSort(adj, k);
        adj.clear();

        for (auto edge : colConditions)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> colSort = topoSort(adj, k);

        if (rowSort.empty() || colSort.empty())
        {
            return {};
        }
        unordered_map<int, pair<int, int>> valuePos;
        for (int i = 0; i < k; i++)
        {
            valuePos[rowSort[i]].first = i;
            valuePos[colSort[i]].second = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int i = 1; i <= k; i++)
        {
            int row = valuePos[i].first;
            int column = valuePos[i].second;
            ans[row][column] = i;
        }
        return ans;
    }
};

signed main()
{
    int k;
    cin >> k;
    vector<vector<int>> rowConditions(k, vector<int>(2));
    vector<vector<int>> colConditions(k, vector<int>(2));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> rowConditions[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> colConditions[i][j];
        }
    }

    Solution ob;
    auto ans = ob.buildMatrix(k, rowConditions, colConditions);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}