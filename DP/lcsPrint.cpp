#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

int func(string s1,string s2,int i,int j,vector<vector<int>>&dp,vector<char>&v){
	if (i<0 || j<0){
		return 0;
	}
	if (dp[i][j]!=-1){
		return dp[i][j];
	}
	
	if (s1[i]==s2[j]){
		v.push_back(s2[j]);
		return dp[i][j]= 1 + func(s1,s2,i-1,j-1,dp,v);
	}
	else{
		return dp[i][j]= max(func(s1,s2,i-1,j,dp,v),func(s1,s2,i,j-1,dp,v));
	}	
}	

int tabulate(string s1,string s2){
	int n = s1.size();
	int m = s2.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (s1[i-1]==s2[j-1]){
				dp[i][j]= 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int counter = 0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (dp[i][j]<=counter) continue;
			else{
				counter++;
				cout<<s1[i-1];
			}
		}
	}
	counter = 0;
}

signed main()
{	
	string s1,s2;
	cin>>s1>>s2;
	if (s1<s2){
		swap(s1,s2);
	}
	int n = s1.size();
	int m = s2.size();
	
	vector<char>v;
	vector<vector<int>>dp(n,vector<int>(m,-1));
	// func(s1,s2,n-1,m-1,dp,v);
	tabulate(s1,s2);
	return 0;
}