// Minimum Cost to Convert String I (Medium)

// Topic: String
// Expected Time Complexity: O(N^2)
// Expected Space Complexity: O(1)
// URL: https://leetcode.com/problems/minimum-cost-to-convert-string-i/

// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].
// You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.
// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

// Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
// Output: 28
// Explanation: To convert the string "abcd" to string "acbe":
// - Change value at index 1 from 'b' to 'c' at a cost of 5.
// - Change value at index 2 from 'c' to 'e' at a cost of 1.
// - Change value at index 2 from 'e' to 'b' at a cost of 2.
// - Change value at index 3 from 'd' to 'e' at a cost of 20.
// The total cost incurred is 5 + 1 + 2 + 20 = 28.
// It can be shown that this is the minimum possible cost.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = original.size();
        vector<vector<int>> dist(26, vector<int>(26, 1e9));

        for (int i = 0; i < 26; i++)
        {
            dist[i][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int row = original[i] - 'a';
            int col = changed[i] - 'a';
            dist[row][col] = min(dist[row][col], cost[i]);
        }
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long row = source[i] - 'a';
            long long col = target[i] - 'a';
            if (dist[row][col] == INT_MAX)
                return -1;
            ans += dist[row][col];
        }
        return ans;
    }
};
signed main()
{
    int n;
    cin >> n;
    string source, target;
    cin >> source >> target;
    vector<char> original(n), changed(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> original[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> changed[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    Solution ob;
    auto ans = ob.minimumCost(source, target, original, changed, cost);
    cout << ans;
    return 0;
}