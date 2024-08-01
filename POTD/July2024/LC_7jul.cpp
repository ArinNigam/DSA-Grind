// Water Bottles (Easy)

// Topic: Simulation
// Expected Time Complexity: O(logN)
// Expected Space Complexity: O(1)
// URL: https://leetcode.com/problems/water-bottles/

// There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
// The operation of drinking a full water bottle turns it into an empty bottle.

// Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.
// Input: numBottles = 15, numExchange = 4
// Output: 19
// Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
// Number of water bottles you can drink: 15 + 3 + 1 = 19.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles;
        int emptyBottles = 0;
        while (numBottles >= numExchange)
        {
            int exchangedBottles = numBottles / numExchange;
            ans += exchangedBottles;
            emptyBottles = numBottles % numExchange;
            numBottles = exchangedBottles + emptyBottles;
        }
        return ans;
    }
};

signed main()
{
    int numBottles, numExchange;
    cin >> numBottles >> numExchange;
    Solution ob;
    auto ans = ob.numWaterBottles(numBottles, numExchange);
    cout << ans;
    return 0;
}