#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long


int fib(int n,vector<int>&dp){
	if (n<2){
		return n;
	}
	if (dp[n]!=-1){
		return dp[n];
	}
	return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int>dp(1500,-1);
	cout<<fib(212,dp);
	return 0;
}