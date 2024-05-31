// Find the Safest Path in a Grid (Medium)
// Topic: BFS
// Expected Time Complexity: O(n^2)
// Expected Space Complexity: O(n^2)
// Problem Statement: https://leetcode.com/problems/find-the-safest-path-in-a-grid/

// You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

// A cell containing a thief if grid[r][c] = 1
// An empty cell if grid[r][c] = 0
// You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

// The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

// Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

// An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

// The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

// Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
// Output: 2
// Explanation: The path depicted in the picture above has a safeness factor of 2 since:
// - The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
// It can be shown that there are no other paths with a higher safeness factor.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, -1, 0, 1};
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &dist)
    {
        int n = grid.size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto it = q.front();
            int x = it.first;
            int y = it.second;

            int s = dist[x][y];
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] > 1 + s)
                {
                    dist[nx][ny] = 1 + s;
                    q.push({nx, ny});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        bfs(grid, dist);
        vector<vector<int>> vis(n, vector<int>(n, 0));
        // shortest path problem to maximise the minimum distance along that path
        priority_queue<pair<int, pair<int, int>>> pq;

        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty())
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int safe = pq.top().first;
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return safe;
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny])
                {
                    int s = min(safe, dist[nx][ny]);
                    pq.push({s, {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
        }
        return -1;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.maximumSafenessFactor(nums);
    cout << ans;
    return 0;
}