// N-th Tribonacci Number (Easy)

// The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,vector<int>&dp){
        if (i==0){
            return 0;
        }
        if (i<=2){
            return 1;
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        return dp[i] = solve(i-1,dp) + solve(i-2,dp) + solve(i-3,dp);

    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
        
    }
};


signed main()
{    
    int n;
    cin>>n;
    Solution ob;
    auto ans = ob.tribonacci(n);
    cout<<ans;
    return 0;
}