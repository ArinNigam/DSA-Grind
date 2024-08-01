// Robot Collisions (Hard)

// Topic: Stack
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
// URL: https://leetcode.com/problems/robot-collisions/

// You are given three arrays positions, healths, and directions, each of length n.
// There are n 1-indexed robots, each having a position on a line, health, and movement direction.
// You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.
// All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.
// If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.
// Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.
// Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.
// Note: The positions may be unsorted.

// Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
// Output: [2,17,9,15,10]
// Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++)
        {
            vp[i].first = positions[i];
            vp[i].second = i;
        }
        sort(vp.begin(), vp.end());
        stack<int> st;
        for (auto ind : vp)
        {
            int i = ind.second;
            if (directions[i] == 'R')
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && healths[i] > 0)
                {
                    int topInd = st.top();
                    st.pop();

                    if (healths[topInd] > healths[i])
                    {
                        healths[topInd]--;
                        healths[i] = 0;
                        st.push(topInd);
                    }
                    else if (healths[topInd] < healths[i])
                    {
                        healths[i]--;
                        healths[topInd] = 0;
                    }
                    else
                    {
                        healths[i] = 0;
                        healths[topInd] = 0;
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (healths[i] > 0)
            {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<int> positions(n), healths(n);
    string directions;
    for (int i = 0; i < n; i++)
    {
        cin >> positions[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> healths[i];
    }
    cin >> directions;

    Solution ob;
    auto ans = ob.survivedRobotsHealths(positions, healths, directions);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}