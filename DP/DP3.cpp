#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long

const int N= 25e2+10;

vector<int>v(N);
int dp[N];
int ans=1;

int func(int i){
	if (dp[i]!=-1){
		return dp[i];
	}
	for (int j=0;j<i;j++){
		if (v[i]>v[j]){
			ans=max(ans,func(j)+1);
		}
	}
	return dp[i]=ans;
}
signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	int ans=0;
	for (int i=0;i<n;i++){
		ans=max(ans,func(i));
	}
	cout<<ans;
	return 0;
}