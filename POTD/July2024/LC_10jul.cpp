// Crawler Log Folder (Easy)

// Topic: Stack
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/crawler-log-folder/

// The Leetcode file system keeps a log each time some user performs a change folder operation.

// The operations are described below:
// "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
// "./" : Remain in the same folder.
// "x/" : Move to the child folder named x (This folder is guaranteed to always exist).
// You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

// The file system starts in the main folder, then the operations in logs are performed.
// Return the minimum number of operations needed to go back to the main folder after the change folder operations.

// Input: logs = ["d1/","d2/","../","d21/","./"]
// Output: 2
// Explanation: Use this change folder operation "../" 2 times and go back to the main folder.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;
        int n = logs.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (logs[i] == "../")
            {
                cnt--;
                cnt = max(cnt, 0);
            }
            else if (logs[i] == "./")
            {
                continue;
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution ob;
    auto ans = ob.minOperations(nums);
    cout << ans;
    return 0;
}