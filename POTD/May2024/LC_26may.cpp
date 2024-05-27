// Student Attendance Record II

// An attendance record for a student can be represented as a string 
// where each character signifies whether the student was absent, late, 
// or present on that day. The record only contains the following three 
// characters:
// 'A': Absent.
// 'L': Late.
// 'P': Present.

// Any student is eligible for an attendance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.


// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

// Example 1:
// Input: n = 2
// Output: 8
// Explanation: There are 8 records with length 2 that are eligible for an award:
// "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    int solve(int n,int cntA, int cntL,vector<vector<vector<int>>>&dp){
        int res = 0;
        if (n==0){
            return 1;
        }
        if (dp[n][cntA][cntL]!=-1){
            return dp[n][cntA][cntL];
        }
        // If student is present
        res += solve(n-1,cntA, 0,dp);
        
        // if student is absent
        if (cntA==0){
            res += solve(n-1,cntA + 1, 0,dp);
            
        }
        res = res % mod;
        // if student isn't late for consecutive 3 days
        if (cntL < 2){
            res += solve(n-1,cntA, cntL + 1,dp);
        }
        
        return dp[n][cntA][cntL] = res%mod;
        
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
       
        return solve(n,0,0,dp);
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    Solution ob;
    auto ans = ob.checkRecord(n);
    cout<<ans;
    return 0;
}