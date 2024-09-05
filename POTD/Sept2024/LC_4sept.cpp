// Walking Robot Simulation (Medium)

// A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:

// -2: Turn left 90 degrees.
// -1: Turn right 90 degrees.
// 1 <= k <= 9: Move forward k units, one unit at a time.
// Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.

// Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).

// Note:

// North means +Y direction.
// East means +X direction.
// South means -Y direction.
// West means -X direction.
// There can be obstacle in [0,0].

// Input: commands = [4,-1,3], obstacles = []
// Output: 25
// Explanation: The robot starts at (0, 0):
// 1. Move north 4 units to (0, 4).
// 2. Turn right.
// 3. Move east 3 units to (3, 4).
// The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int multi = 60001;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // N,E,S,W
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        unordered_set<int>st;
        for(auto it:obstacles){
            st.insert(it[0] + it[1] * multi);
        }

        int currX = 0;
        int currY = 0;

        int maxi = 0;

        int dirn = 0;
        // N:0
        // E:1
        // S:2
        // W:3
        for(auto it : commands) {
            if (it == -1) {
                dirn = (dirn + 1) % 4;
            } 
            else if (it == -2) {
                dirn = (dirn + 3) % 4;
            } 
            else {
                for(int k = 0; k < it; k++) {
                    int nx = currX + dx[dirn];
                    int ny = currY + dy[dirn];
                    if (st.find(nx + ny * multi) != st.end()) {
                        break;
                    }
                    currX = nx;
                    currY = ny;
                    maxi = max(maxi, currX*currX + currY*currY);
                }
            }
        }
        return maxi;

    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>commands(n);
    vector<vector<int>>obstacles(n,vector<int>(2));
    for (int i=0;i<n;i++){
        cin>>commands[i];
    }
    for (int i=0;i<n;i++){
        cin>>obstacles[i][0]>>obstacles[i][1];
    }
    Solution ob;
    auto ans = ob.robotSim(commands,obstacles);
    cout<<ans;
    return 0;
}