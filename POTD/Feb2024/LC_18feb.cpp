//Meeting Rooms III (Hard)

// You are given an integer n. There are n rooms numbered from 0 to n - 1.
// You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.
// Meetings are allocated to rooms in the following manner:

// Each meeting will take place in the unused room with the lowest number.
// If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
// When a room becomes unused, meetings that have an earlier original start time should be given the room.

// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
// Output: 0
// Explanation:
// - At time 0, both rooms are not being used. The first meeting starts in room 0.
// - At time 1, only room 1 is not being used. The second meeting starts in room 1.
// - At time 2, both rooms are being used. The third meeting is delayed.
// - At time 3, both rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
// - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
// Both rooms 0 and 1 held 2 meetings, so we return 0.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n,0);
        vector< long long > times(n,0);
        sort(meetings.begin(),meetings.end());

        for(int i=0;i<meetings.size();i++){
            int start = meetings[i][0], end = meetings[i][1];
            bool flag = false;
            int minind = -1;
            long long val = 1e18;
            for(int j=0;j<n;j++){
                if(times[j]<val) val = times[j], minind = j;
                if(times[j] <= start){
                    flag = true;
                    ans[j]++;
                    times[j] = end;
                    break;
                }
            }
            if(!flag){
                ans[minind]++;
                times[minind]+=(1ll*(end-start));
            }
        }
        int maxi = -1, id = -1;
        for(int i =0;i<n;i++){
            if(ans[i]>maxi) maxi = ans[i], id = i;
        }
        return id;
    }
};



signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2,-1));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.mostBooked(n,nums);
    cout<<ans;
    return 0;
}