// Perfect Squares(Medium)
// Given an integer n, return the least number of perfect square numbers that sum to n.
// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int sum,vector<int>&dp){
        if (sum<0){
            return INT_MAX;
        }
        if (sum==0){
            return 0;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ans = INT_MAX;
        for (int i=1;i*i<=sum;i++){
            ans = min(ans,1+solve(sum-i*i,dp));
        }
        return dp[sum]=ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
      
        return solve(n,dp);
    }
};
signed main()
{    
    int n;
    cin>>n;
    
    Solution ob;
    auto ans = ob.numSquares(n);
    cout<<ans;
    return 0;
}