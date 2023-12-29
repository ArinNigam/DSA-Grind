// Minimum Path Sum 
// Grid Problem 3
// Caluculate the minimum sum to go from top left -> bottom right

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=2e2+5;
vector<int>nums[N];

int func(int i,int j,vector<vector<int>> &nums,vector<vector<int>> &dp){
	if (i==0 && j==0){
		return nums[0][0];
	}
	if (i<0 || j<0 ){
		return 1e9;
	}
	if (dp[i][j]!=-1){
		return dp[i][j];
	}
	int left = nums[i][j] + func(i-1,j,nums,dp);
	int right = nums[i][j] + func(i,j-1,nums,dp);
	return dp[i][j] = min(left,right);
	
}	
signed main()
{	
	int m,n;
	cin>>m>>n;
	vector<vector<int>>dp(n,vector<int>(m,-1));
	vector<vector<int>>nums(n,vector<int>(m,0));
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			cin>>nums[i][j];
		}
	}
	// cout<<func(m-1,n-1,nums,dp);
	
	
	// Tabulation
	
	// For space optimise replace dp[i]=prev
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if(i==0 && j==0){
				dp[i][j]=nums[i][j];
			}
			else{
				int up=nums[i][j];
				int left=nums[i][j];
				if (i>0){
					up += dp[i-1][j];
				}
				else{
					up+=1e9;
				}
				if (j>0){
					left += dp[i][j-1];
				}
				else{
					left+=1e9;
				}
				dp[i][j] = min(up,left);
			}
		}
		
	}
	cout<<dp[n-1][m-1];
	return 0;
}