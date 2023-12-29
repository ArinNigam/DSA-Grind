#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

int func(int i,int j, vector<vector<int>>& nums,vector<vector<int>>& dp){
	if (i==0){
		return nums[0][j];
	}
	if (j<0 || j>=nums.size()){
		return 1e9;
	}
	if (dp[i][j]!=-1){
		return dp[i][j];
	}
	int left = nums[i][j] + func(i-1,j-1,nums,dp);
	int st = nums[i][j] + func(i-1,j,nums,dp);
	int right= nums[i][j] + func(i-1,j+1,nums,dp);
	return dp[i][j] = min({left,st,right});
}	
signed main()
{	
	int n;
	cin>>n;
	vector<vector<int>>nums(n,vector<int>(n,0));
	vector<vector<int>>dp(n,vector<int>(n,-1));
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>nums[i][j];
		}
	}
	int ans=INT_MAX;
	for (int i=0;i<n;i++){
		ans= min(ans,func(n-1,i,nums,dp));
	}
	cout<< ans << endl;
	
	
	// Tabulate 
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==0){
				dp[i][j]=nums[i][j];
			}
			else{
				int left = nums[i][j];
				if (j-1>=0) left+= dp[i-1][j-1];
				else left+= 1e9;
				
				int st = nums[i][j] + dp[i-1][j];
				
				int right = nums[i][j];
				if (j+1>=n) right+= dp[i-1][j+1];
				else left+= 1e9;
				
				dp[i][j] = min({left,st,right});
			}
		}
	}
	
	for (int i=0;i<n;i++){
		ans=min(ans,dp[n-1][i]);
	}
	cout<<ans<<endl;
	
	return 0;
}