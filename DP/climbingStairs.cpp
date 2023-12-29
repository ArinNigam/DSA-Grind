// Climbing Stairs
// 1) DP approach O(N) TC SC  
// 2) Tabular dp O(N) TC & O(1)SC

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e3+5;
int dp[N];
//DP Approach 
int func(int i, vector<int>&dp){
    if (i==0) return 1;
    if (i==1) return 1;
    if (dp[i]!=-1) return dp[i];
    return dp[i]= func(i-1,dp)+func(i-2,dp);
}
signed main()
{   
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    
    // Tabular Form 
    dp[0]= 1;
    dp[1]= 1;
  
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    cout<<dp[n];
    cout<<endl;
    cout<<func(n,dp);
}