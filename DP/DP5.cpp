#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long

int dp[310][10010];

int func(int ind,int amount,vector<int>& coins){
	if (amount==0){
		return 1;
	}
	if (ind<0){
		return 0;
	}
	if (dp[ind][amount]!=-1){
		return dp[ind][amount];
	}
	int ans=0;
	for (int coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind]){
		ans+= func(ind-1,amount-coin_amount,coins);
	}
	return dp[ind][amount]=ans;
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
	cout<<func(n-1,x,coins);
	return 0;
}