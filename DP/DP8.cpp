#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long
const int N=1010;

int dp[1010];

vector<int>prices(N);
int func(int len,vector<int>&prices){
	int ans=0;
	if (len==0){
		return 0;
	}
	if (dp[len]!=-1){
		return dp[len];
	}
	for (int len_to_cut=1; len_to_cut<=prices.size();len_to_cut++){
		if (len-len_to_cut>=0){
			ans=max(ans,func(len-len_to_cut,prices)+ prices[len_to_cut-1]);
		}
		
	}
	return dp[len]=ans;
}

signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>prices[i];
	}
	cout<<func(n,prices);
	return 0;
}