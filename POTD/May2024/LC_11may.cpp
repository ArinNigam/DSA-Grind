// Minimum Cost to Hire K Workers (Hard)
// Topic: Heap (Priority Queue)
// Expected Time Complexity: O(nlogn)
// Expected Space Complexity: O(n)
// Problem Statement: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

// There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
// We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
// Every worker in the paid group must be paid at least their minimum wage expectation.
// In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.
// Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.

// Example 1:

// Input: quality = [10,20,5], wage = [70,50,30], k = 2
// Output: 105.00000
// Explanation: We pay 70 to 0th worker and 35 to 2nd worker.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();

        vector<pair<double, int>> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back({(double)wage[i] / quality[i], i});
        }

        sort(ans.begin(), ans.end());
        priority_queue<int> pq;

        int qualitySum = 0;
        double maxi = 0;

        for (int i = 0; i < k; i++)
        {
            qualitySum += quality[ans[i].second];
            maxi = max(maxi, ans[i].first);
            pq.push(quality[ans[i].second]);
        }

        double res = maxi * qualitySum;

        for (int i = k; i < n; i++)
        {
            maxi = max(maxi, ans[i].first);
            qualitySum -= pq.top();
            pq.pop();

            qualitySum += quality[ans[i].second];
            pq.push(quality[ans[i].second]);
            res = min(res, maxi * qualitySum);
        }
        return res;
    }
};

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> quality(n);
    vector<int> wage(n);
    for (int i = 0; i < n; i++)
    {
        cin >> quality[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wage[i];
    }
    Solution ob;
    auto ans = ob.mincostToHireWorkers(quality, wage, k);
    cout << ans;
    return 0;
}