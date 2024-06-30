// Most Profit Assigning Work( Medium )
// Topic: Arrays
// Expected Time Complexcity: O(NlogN)
// Expected Space Complexity: O(N)
// Problem Statement: https://leetcode.com/problems/most-profit-assigning-work/

// You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
// difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
// worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
// Every worker can be assigned at most one job, but one job can be completed multiple times.
// Return the maximum profit we can achieve after assigning the workers to the jobs.

// Example 1:
// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        sort(worker.begin(),worker.end());
        vector<pair<int,int>>jobs(n);
        for(int i=0;i<n;i++){
            jobs[i].first = difficulty[i];
            jobs[i].second = profit[i];
        }
        sort(jobs.begin(),jobs.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        int maxi = 0;
        while(j<m){
            while(i<n && jobs[i].first <= worker[j]){
                maxi = max(maxi,jobs[i].second);
                i++;
            }
            ans += maxi;
            j++;
        }
        return ans;
    }
};
signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<int>difficulty(n),profit(n),worker(m);
    for (int i=0;i<n;i++){
        cin>>difficulty[i];
    }
    for (int i=0;i<n;i++){
        cin>>profit[i];
    }
    for (int i=0;i<m;i++){
        cin>>worker[i];
    }
    Solution ob;
    auto ans = ob.maxProfitAssignment(difficulty,profit,worker);
    cout<<ans;
    return 0;
}