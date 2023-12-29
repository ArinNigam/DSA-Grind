 //2D DP
// A person doing 3 activity in n days Find max merit points

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;


int func(int day,int last,vector<vector<int>>& nums,vector<vector<int>>&dp ){
	// Write in terms of Index
	// Do stuffs on that index
	// Find Max
	if (dp[day][last]!=-1){
		return dp[day][last];
	}
	if (day == 0){
		int ansi=0;
		for (int i=0;i<3;i++){
			if (i!=last){
				ansi=max(ansi,nums[0][i]);
			}
		}
		return dp[day][last]=ansi;
	}
	int ansi=0;
	for (int i=0;i<3;i++){
		if (i!=last){
			int curri= nums[day][i] + func(day-1,i,nums,dp);
			ansi = max(ansi,curri);
		}
	}
	return dp[day][last]=ansi;
}
	
signed main()
{	
	int n;
	cin>>n;
	vector<vector<int>>nums(n,vector<int>(n,0));
	vector<vector<int>>dp1(n,vector<int>(4,-1));
	
	for (int i=0;i<n;i++){
		for (int j=0;j<3;j++){
			cin>>nums[i][j];
		}
	}
	cout<<func(n-1,3,nums,dp1)<<endl;
	
	// Tabulation
	vector<vector<int>>dp(n,vector<int>(4,0));
	
	dp[0][0]=max(nums[0][1],nums[0][2]);
	dp[0][1]=max(nums[0][0],nums[0][2]);
	dp[0][2]=max(nums[0][0],nums[0][1]);
	dp[0][3]=max({nums[0][0],nums[0][1],nums[0][2]});
	for (int day=1;day<n;day++){
		for (int last=0; last<4;last++ ){
			dp[day][last]= 0;
			for (int task =0 ;task<3;task++){
				if (task != last){
					dp[day][last]= max(dp[day][last],nums[day][task]+dp[day-1][task]);
				}	
			}
		}
	}
	cout<<dp[n-1][3]<<endl;
	return 0;
}