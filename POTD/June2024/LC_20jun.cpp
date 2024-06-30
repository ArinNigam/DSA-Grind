// Magnetic Force Between Two Balls (Medium)
// Topic: Binary Search
// Expected Time Complexcity: O(NlogN)
// Expected Space Complexity: O(1)
// Problem Statement: https://leetcode.com/problems/magnetic-force-between-two-balls/

// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
// Given the integer array position and the integer m. Return the required force.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (canWePlace(position, mid, m))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canWePlace(const vector<int> &arr, int dist, int balls)
    {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - lastPlaced >= dist)
            {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls)
            {
                return true;
            }
        }
        return false;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<int> position(n);
    for (int i = 0; i < n; i++)
    {
        cin >> position[i];
    }
    int m;
    cin >> m;
    Solution ob;
    auto ans = ob.maxDistance(position, m);
    cout << ans;
    return 0;
}