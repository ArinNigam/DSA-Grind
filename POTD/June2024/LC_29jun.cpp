// All Ancestors of a Node in a Directed Acyclic Graph (Medium)
// Topic: Graphs
// Expected Time Complexcity: O(V+E)
// Expected Space Complexity: O(N)
// Problem Statement: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

// You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).
// You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.
// Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.
// A node u is an ancestor of another node v if u can reach v via a set of edges.

// Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
// Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
// Explanation:
// The above diagram represents the input graph.
// - Nodes 0, 1, and 2 do not have any ancestors.
// - Node 3 has two ancestors 0 and 1.
// - Node 4 has two ancestors 0 and 2.
// - Node 5 has three ancestors 0, 1, and 3.
// - Node 6 has five ancestors 0, 1, 2, 3, and 4.
// - Node 7 has four ancestors 0, 1, 2, and 3.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<vector<int>> &ans)
    {

        for (auto it : adj[node])
        {
            if (ans[it].size() == 0 || ans[it].back() != parent)
            {
                ans[it].push_back(parent);
                dfs(it, parent, adj, ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            dfs(i, i, adj, ans);
        }
        return ans;
    }
};
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.getAncestors(n, nums);
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
