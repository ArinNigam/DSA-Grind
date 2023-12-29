// Buy and Sell Stocks 
// only buy and sell combination allowed
// There is a cooldown period 

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;

int func(vector<int>& Arr, int n, int i, int j, vector<vector<int>>& dp ){

if(i>=n ) return 0; 

if(dp[i][j]!=-1)
   	return dp[i][j];
    
int profit;

if(j==0){
    profit = max(0+func(Arr,n,i+1,0,dp), 
                -Arr[i] + func(Arr,n,i+1,1,dp));
}

if(j==1){
    profit = max(0+func(Arr,n,i+1,1,dp),
                Arr[i] + func(Arr,n,i+2,0,dp));
}

return dp[i][j] = profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return func(prices,n,0,0,dp);
}

int tabulate(vector<int>& prices){
	int n = prices.size();
	// dp [n-1][2]
	vector<vector<int>> dp(n+2,vector<int>(2,0));
	for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            int profit;
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], 
                            -prices[ind] + dp[ind+1][1]);
             }

            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1],
                            prices[ind] + dp[ind+2][0]);
             
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
}
int optimised(vector<int> &prices){
	int n = prices.size();
	// dp [n-1][2][+1]
    vector<int> cur(2,0);
    vector<int> front1(2,0);
    vector<int> front2(2,0);
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            int profit;
            if(buy==0){// We can buy the stoc
                profit = max(0+front1[0], 
                            -prices[ind] + front1[1]);
             }

            if(buy==1){// We can sell the stoc
                profit = max(0+front1[1],
                            prices[ind] + front2[0]);
            }
            cur[buy]=profit;
        }
        front2 = front1;
        front1 = cur;
        
    }
    
    return cur[0];
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