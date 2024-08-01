// Average Waiting Time (Medium)

// Topic: Array
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)
// URL: https://leetcode.com/problems/average-waiting-time/

// There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:
// arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
// timei is the time needed to prepare the order of the ith customer.
// When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.
// Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.

// Input: customers = [[1,2],[2,5],[4,3]]
// Output: 5.00000
// Explanation:
// 1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
// 2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
// 3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
// So the average waiting time = (2 + 6 + 7) / 3 = 5.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int n = customers.size();
        int start = customers[0][0];
        int orderTime = customers[0][1];
        int waitingTime = start + orderTime;
        long long ans = customers[0][1];
        for (int i = 1; i < n; i++)
        {
            start = customers[i][0];
            if (waitingTime > start)
            {
                ans += waitingTime - start;
            }
            else
            {
                waitingTime = start;
            }
            orderTime = customers[i][1];
            waitingTime += orderTime;
            ans += orderTime;
        }
        return (double)ans / n;
    }
};
signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.averageWaitingTime(nums);
    cout << ans;
    return 0;
}