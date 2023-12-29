// Buy and Sell Stocks
// Atmost 2 transactions 
// only buy and sell combination allowed

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;

int func(vector<int>& Arr, int n, int i, int j, int k, vector<vector<vector<int>>>& dp ){

if(i==n || k==0) return 0; 

if(dp[i][j][k]!=-1)
   	return dp[i][j][k];
    
int profit;

if(j==0){
    profit = max(0+func(Arr,n,i+1,0,k,dp), 
                -Arr[i] + func(Arr,n,i+1,1,k,dp));
}

if(j==1){
    profit = max(0+func(Arr,n,i+1,1,k,dp),
                Arr[i] + func(Arr,n,i+1,0,k-1,dp));
}

return dp[i][j][k] = profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>
    (2,vector<int>(3,-1)));
    return func(prices,n,0,0,2,dp);
}

int tabulate(vector<int>& prices){
	int n = prices.size();
	// dp [n-1][2][3]
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
	for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], 
                                -prices[ind] + dp[ind+1][1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],
                                prices[ind] + dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    return dp[0][0][2];
}
int optimised(vector<int> &prices){
	int n = prices.size();
	// dp [n-1][2][3]
	vector<vector<int>> ahead(2,vector<int> (3,0));
    vector<vector<int>> cur(2,vector<int> (3,0));
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    cur[buy][cap] = max(0+ahead[0][cap], 
                                -prices[ind] + ahead[1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    cur[buy][cap] = max(0+ahead[1][cap],
                                prices[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    
    return ahead[0][2];
}
signed main()
{	
	int n;
	cin>>n;
	vector<int>nums(n);
	for (int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<< maxProfit(nums);
	cout<< tabulate(nums);
	cout<< optimised(nums);
	return 0;
}