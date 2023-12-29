// Perfect subset Sum 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int help(int ind,int arr[],int n,int sum,vector<vector<int>>&dp){
       if (ind==0){
            if (arr[0]==0 && sum==0) return 2;
            if (arr[0]==sum || sum==0) return 1;
           return 0;
       }
       if (dp[ind][sum]!=-1) return dp[ind][sum];
       int pick = 0;
       if( arr[ind]<=sum){
           pick = help(ind-1,arr,n,sum-arr[ind],dp)%mod;
       }
       int notPick = help(ind-1,arr,n,sum,dp)%mod;
       return dp[ind][sum] = (pick%mod+notPick%mod)%mod;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return help(n-1,arr,n,sum,dp);
        
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution ob;
    auto ans = ob.perfectSum(arr,n,k);
    cout<<ans;
    return 0;
}