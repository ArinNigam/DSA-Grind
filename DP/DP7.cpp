#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long

int val[105],wt[105];
ll dp[105][100005];

//funct is returning a minimum weight
ll func(int ind, int val_left ){
	if (val_left==0){
		return 0;
	}
	if (ind<0){
		return 1e15;
	}
	if(dp[ind][val_left]!=-1){
		return dp[ind][val_left];
	}
	//Not choosing
	ll ans=func(ind-1,val_left);
	//choosing
	if (val_left-val[ind]>=0)
		ans=min(ans,func(ind-1,val_left-val[ind])+wt[ind]);
	return dp[ind][val_left]=ans;
}
	
signed main()
{	
	memset(dp,-1,sizeof(dp));
	int n,w;
	cin>>n>>w;
	for (int i=0;i<n;i++){
		cin>>wt[i]>>val[i];
	}
	int max_val=1e5;
	for (int i=max_val;i>=0;i--){
		if (func(n-1,i)<=w){
			cout<<i<<endl;
			break;
		}
	}
	
	return 0;
}