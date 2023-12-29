#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long

const int N=1e6+10;

int dp[1000005];


int func(int amount,vector<int>& coins){
	if (amount==0){
		return 0;
	}
	if (dp[amount]!=-1){
		return dp[amount];
	}
	int ans=INT_MAX;
	for (int coin : coins){
		if (amount-coin>=0){
		ans= min(ans + 0LL ,func(amount-coin,coins)+1LL);
		}
	}
	return dp[amount]=ans;
}


signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int n,x;
	cin>>n>>x;
	vector<int>coins(n);
	for (int i=0;i<n;i++){
		cin>>coins[i];
	}
	int ans= func(x,coins);
    if(ans==INT_MAX)
    	cout<<-1;
    else cout<<ans;
	
	return 0;
}