// Coin Change II (Medium)
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.


// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.

// Input: amount = 10, coins = [10]
// Output: 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(int ind,int sum,vector<int>& coins,vector<vector<int>>&dp){
        if (ind==0){
            return coins[ind]==sum;
        }
        if (sum==0) return 1;
        if (sum<0) return 0;
        if (dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int pick = 0;
        if (sum>=coins[ind]){
            pick = 1 + func(ind,sum-coins[ind],coins,dp);
        }
        int notPick = func(ind-1,sum,coins,dp);

        return dp[ind][sum] = pick + notPick;
    }
    int change(int sum,vector<int> &coins) {
        int n = coins.size();
        // // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return func(n-1,sum,coins,dp);
        vector<vector<int>>dp(n+1,vector<int>(sum,0));
        for (int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for (int j=1;j<=sum;j++){
                if (j>=coins[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

signed main()
{    
    int n,amt;
    cin>>n>>amt;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.change(amt,nums);
    cout<<ans;
    return 0;
}