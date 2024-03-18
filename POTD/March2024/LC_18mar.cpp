// Minimum Number of Arrows to Burst Balloons (Medium)
// There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
// Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1] < v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        int start = points[0][0];
        int end = points[0][1];
        int cnt = 1;
        for(int i=1;i<n;i++){
            if (points[i][0] > end){
                cnt++;
                end = points[i][1];
            }
        }
        return cnt;
    }
};
signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.findMinArrowShots(nums);
    cout<<ans;
    return 0;
}