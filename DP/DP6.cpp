#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long

int val[105],wt[105];
ll dp[105][100005];

ll func(int ind, int wt_left ){
	if (wt_left==0){
		return 0;
	}
	if (ind<0){
		return 0;
	}
	if (dp[ind][wt_left]!=-1){
		return dp[ind][wt_left];
	}
	//Dont choose item at index
	ll ans=func(ind-1,wt_left);
	//choose item at index
	if (wt_left-wt[ind]>=0){
		ans= max(ans,func(ind-1,wt_left-wt[ind])+val[ind]);
	}
	return dp[ind][wt_left]=ans;
}
	
signed main()
{	
	memset(dp,-1,sizeof(dp));
	int n,w;
	cin>>n>>w;
	for (int i=0;i<n;i++){
		cin>>wt[i]>>val[i];
	}
	cout<< func(n-1,w);
	
	return 0;
}