#include<bits/stdc++.h>
using namespace std;

#define append(v) push_back(v)
#define pop() pop_back()

#define endl '\n'
#define ll long long

#define sum(v) accumulate(v.begin(),v.end(),0);
#define sort(v) sort(v.begin(),v.end());

const int N=1e3+5;
string s1,s2;
int dp[1005][1005];
int func(int i,int j,string &s1, string &s2){
	if (i<0 || j<0){
		return 0;
	}
	if (dp[i][j]!=-1){
		return dp[i][j];
	}
	return dp[i][j]=max({func(i-1,j,s1,s2),func(i,j-1,s1,s2),func(i-1,j-1,s1,s2)+(s1[i]==s2[j])});
	
	
}
signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>s1>>s2;
	cout<<func(s1.size()-1,s2.size()-1,s1,s2);
	return 0;
}