// Maximum Profit in Job Scheduling ( Hard )

// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job. 
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int start,int end,vector<vector<int>>&jobs,vector<int>&dp){
        int n = jobs.size();
        if (start == n){
            return 0;
        }
        if (jobs[start][0] < end){
            return solve(start + 1 , end , jobs, dp);
        }
        if (dp[start]!=-1){
            return dp[start];
        }
        vector<int> v = {jobs[start][1], 0, 0};
        int nextIdx = lower_bound(jobs.begin(), jobs.end(), v) - jobs.begin();
        return dp[start] = max(solve(start+1,end,jobs,dp), jobs[start][2]+solve(nextIdx,jobs[start][1],jobs,dp));
    }   
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        vector<vector<int>>jobs;
        int n = startTime.size();
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        vector<int>dp(n,-1);
        sort(jobs.begin(),jobs.end());
        return solve(0,0,jobs,dp);
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>startTime(n);
    vector<int>endTime(n);
    vector<int>profit(n);
    for (int i=0;i<n;i++){
        cin>>startTime[i];
    }
    for (int i=0;i<n;i++){
        cin>>endTime[i];
    }
    for (int i=0;i<n;i++){
        cin>>profit[i];
    }
    Solution ob;
    auto ans = ob.jobScheduling(startTime,endTime,profit);
    cout<<ans;
    return 0;
}