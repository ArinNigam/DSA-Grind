// Filling Bookcase Shelves (Medium)

// Topic: Dynamic Programming
// Expected Time Complexity: O(n^2)
// Expected Space Complexity: O(n)
// URL: https://leetcode.com/problems/filling-bookcase-shelves/

// You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.
// We want to place these books in order onto bookcase shelves that have a total width shelfWidth.
// We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.
// Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.
// For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
// Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

// Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
// Output: 6
// Explanation:
// The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
// Notice that book number 2 does not have to be on the first shelf.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int total_width = 0;
            int maxi = 0;
            for (int j = i; j > 0; j--)
            {
                total_width += books[j - 1][0];
                if (total_width > shelfWidth)
                {
                    break;
                }
                maxi = max(maxi, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxi);
            }
        }
        return dp[n];
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i][0] >> nums[i][1];
    }
    int shelfWidth;
    cin >> shelfWidth;
    Solution ob;
    auto ans = ob.minHeightShelves(nums, shelfWidth);
    cout << ans;
    return 0;
}