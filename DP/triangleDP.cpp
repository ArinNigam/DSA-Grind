#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

int func(int i,int j,vector<vector<int>>& nums,vector<vector<int>>& dp){
	int n = nums.size();
	
	if (i==nums.size()-1){
		return nums[n-1][j];
	}
	if (dp[i][j]!=-1){
		return dp[i][j];
	}
	int down = nums[i][j];
	int diag_right = nums[i][j];
	
	if (i<n-1) down += func(i+1,j,nums,dp);
	if (i<n-1 && j<n-1) diag_right += func(i+1,j+1,nums,dp);
	return min(down,diag_right);
}	
signed main()
{	
	int n,m;
	cin>>n>>m;
	vector<vector<int>>nums(n,vector<int>(m));
	vector<vector<int>>dp(n,vector<int>(m,-1));
	auto dp1 = dp;
	for (int i=0;i<n;i++){
		for (int j=0;j<i+1;j++){
			cin>>nums[i][j];
		}
	}
	cout<<func(0,0,nums,dp);
	
	// Tabulate
	for (int j=0;j<n;j++){
		dp[n-1][j] = nums[n-1][j];
	}
	for (int i=n-2;i>=0;i--){
		for (int j=i;j>=0;j--){
			int down = nums[i][j] + dp[i+1][j];
			int diag = nums[i][j] + dp[i+1][j+1];
			dp[i][j]=min(down,diag);
		}
	}
	cout<<dp[0][0];
	
	
	return 0;
}