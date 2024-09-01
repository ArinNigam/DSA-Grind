// Modify Graph Edge Weights (Hard)

// You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.
// Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).
// Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.
// Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.
// Note: You are not allowed to modify the weights of edges with initial positive weights.

// Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
// Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
// Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int INF = 2e9;
    int dijisktra(int n, vector<vector<pair<int, int>>> &adj, int s, int d)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            if (node == d)
            {
                break;
            }
            for (auto j : adj[node])
            {
                int adjNode = j.first;
                int wt = j.second;

                if (dist[adjNode] > dis + wt)
                {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist[d];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int s, int d, int k)
    {

        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges)
        {
            if (edge[2] == -1)
                continue;
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int shortestPath = dijisktra(n, adj, s, d);
        if (shortestPath < k)
            return {};
        bool isEqual = shortestPath == k;

        for (auto &edge : edges)
        {
            if (edge[2] != -1)
                continue;

            edge[2] = isEqual ? INF : 1;
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});

            if (!isEqual)
            {
                int newShortestPath = dijisktra(n, adj, s, d);
                if (newShortestPath <= k)
                {
                    isEqual = true;
                    edge[2] += k - newShortestPath;
                }
            }
        }

        if (isEqual)
            return edges;
        return {};
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> edges[i][j];
        }
    }
    int s, d, k;
    cin >> s >> d >> k;
    Solution ob;
    auto ans = ob.modifiedGraphEdges(n, edges, s, d, k);
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