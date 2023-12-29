// Grid Problem
// Unique Paths can only travel DOWN RIGHT
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;

// TC - O(m*n) SC - O((n-1)+(m-1))+O(m*n)
int func(int i,int j,vector<vector<int>>&dp){
	if (i==0 && j==0){
		return 1;
	}
	if (i<0 || j<0){
		return 0;
	}
	if (dp[i][j]!=-1){
		return dp[i][j];
	}
	return dp[i][j]= func(i-1,j,dp)+func(i,j-1,dp);
}	
signed main()
{	
	int m,n;
	cin>>m>>n;
	vector<vector<int>>dp(m,vector<int>(n,-1));
	cout<<func(m-1,n-1,dp)<<endl;
	
	//Tabulating 
	// TC - O(m*n) SC - O(m*n)
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (i==0 && j==0){
				dp[i][j]=1;
				continue;
			}
		
			int up=0;
			int right=0;
			if (i>0){
				up= dp[i-1][j];
			}
			if (j>0){
				right = dp[i][j-1];
			}	
			dp[i][j]= up + right;
	
			
		}
	}
	cout<<dp[m-1][n-1]<<endl;
	
	// Space Optimising it into 1D array from 2D array
	// TC - O(m*n) SC - O(n)
	vector<int> prev(n,0);
	for (int i=0;i<m;i++){
		vector<int> temp(n,0);
		for (int j=0;j<n;j++){
			if (i==0 && j==0){
				temp[j]=1;
				continue;
			}
			
			int up=0;
			int right=0;
			if (i>0){
				up=prev[j];
			}
			if (j>0){
				right =temp[j-1];
			}	
			temp[j]= up + right;
		}
		prev = temp;
	}
	cout<<prev[n-1]<<endl;
	
	// Optimal Solution choosing ways
	// m+n-2 C m-1 or m+n-2 C n-1
	// TC - O(m) SC - O(1)
	int N = m+n-2;
	int r= m-1;
	double res=1;
	for (int i=1;i<=r;i++){
		res = res * (N - r + i)/i;
	}
	cout<<(int)res;
	return 0;
}