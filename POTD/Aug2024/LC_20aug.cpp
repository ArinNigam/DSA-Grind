// Stone Game II (Medium)

// Alice and Bob continue their games with piles of stones.There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].The objective of the game is to end with the most stones.
// Alice and Bob take turns, with Alice starting first.
// On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

// The game continues until all the stones have been taken.

// Assuming Alice and Bob play optimally,
// return the maximum number of stones Alice can get.
// Input : piles = [ 2, 7, 9, 4, 4 ]
// Output : 10

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int m = 1; m <= n; m++)
            {
                if (i + 2 * m >= n)
                {
                    dp[i][m] = suffixSum[i];
                }
                else
                {
                    for (int x = 1; x <= 2 * m; x++)
                    {
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};
signed main()
{
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    Solution ob;
    auto ans = ob.stoneGameII(piles);
    cout << ans;
    return 0;
}