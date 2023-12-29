// Buy and Sell Stocks 
// only buy and sell combination allowed
// There is a transaction fee
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;

int func(vector<int>& Arr, int n, int i, int j, int k, vector<vector<int>>& dp ){

if(i==n) return 0; 

if(dp[i][j]!=-1)
    return dp[i][j];
    
int profit;

if(j==0){
    profit = max(0+func(Arr,n,i+1,0,k,dp), 
                -Arr[i] + func(Arr,n,i+1,1,k,dp));
}

if(j==1){
    profit = max(0+func(Arr,n,i+1,1,k,dp),
                Arr[i] - k + func(Arr,n,i+1,0,k,dp));
}

return dp[i][j] = profit;
}
int maxProfit(vector<int>& prices,int k) {
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return func(prices,n,0,0,k,dp);
}

int tabulate(vector<int>& prices,int k){
    int n = prices.size();
    if (n==0) return 0;
    // dp [n-1][2]
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            int profit;
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], 
                            -prices[ind] + dp[ind+1][1]);
            }
            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1],
                            prices[ind]-k + dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        
        }
    }
    return dp[0][0];
}
int optimised(vector<int> &prices,int k){
    int n = prices.size();
    // dp [n-1][2]
    if (n==0) return 0;
    vector<int> ahead(2,0);
    vector<int> cur(2,0);
     ahead[0] = ahead[1] = 0;
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                cur[buy] = max(0+ahead[0], 
                            -prices[ind] + ahead[1]);
             }

            if(buy==1){// We can sell the stock
                cur[buy] = max(0+ahead[1],
                            prices[ind]-k + ahead[0]);
                
            }
        }
        ahead = cur;
    }
    
    return ahead[0];
}
signed main()
{   
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<< maxProfit(nums,k);
    cout<< tabulate(nums,k);
    cout<< optimised(nums,k);
    return 0;
}