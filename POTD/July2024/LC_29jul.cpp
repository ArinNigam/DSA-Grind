// Count Number of Teams (Medium)

// Topic: Array
// Expected Time Complexity: O(n^3)
// Expected Space Complexity: O(1)
// URL: https://leetcode.com/problems/count-number-of-teams/

// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
// You have to form a team of 3 soldiers amongst them under the following rules:
// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int cnt = 0;
        int n = rating.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if ((rating[i] > rating[j] && rating[j] > rating[k]) || (rating[i] < rating[j] && rating[j] < rating[k]))
                    {
                        cnt++;
                    }
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
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution ob;
    auto ans = ob.numTeams(nums);
    cout << ans;
    return 0;
}