#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long

const int N = 10e5+10;

vector<int>h(N);
int dp[N];
int k;
int func(int i){
	if (i==0){
		return 0;
	}
	if (dp[i]!=-1){
		return dp[i];
	}
	int cost = INT_MAX;
	for (int j=1;j<=k;j++){
		if (i-j>=0){
			cost = min (cost,func(i-j)+ abs(h[i]-h[i-j]));
		}
	}
		
	return dp[i]=cost;
}
signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<n;i++){
		cin>>h[i];
	}
	cout<<func(n-1);
	return 0;
}