#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long

#define sum(v) accumulate(v.begin(),v.end(),0);
#define sort(v) sort(v.begin(),v.end());

const int N=1e5+5;

int dp[55];
int func(int i,string &s){
	if (i<0){
		return 0;
	}
	if (dp[i]!=-1){
		return dp[i];
	}
	return dp[i]=max(func(i-1,s),func(i-1,s)+s[i]);
	
	
}
signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	cout<<min(m*b+a,n);
	return 0;
}