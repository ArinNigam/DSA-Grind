// Insert Interval (Medium)
// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Note that you don't need to modify intervals in-place. You can make a new array and return it.

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i=1;i<intervals.size();i++){
            if (intervals[i][0] <= end){
                end = max(end,intervals[i][1]);
            }
            else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};


signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums1(n,vector<int>(2));
    vector<int>nums2(2);
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin>>nums1[i][j];
        }
    }
    for (int i=0;i<2;i++){
        cin>>nums2[i];
    }
    Solution ob;
    auto ans = ob.insert(nums1,nums2);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}