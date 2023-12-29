//Frog Jump2
// Minimum Number of energy frog takes
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
int dp[N];
int k;
int func(int i,vector<int>& nums){
	if (i==0){
		return 0;
	}
	if (dp[i]!=-1){
		return dp[i];
	}
	int ans=INT_MAX;
	for (int j=1;j<=k;j++){
		if (i>=j){
			int jmp= func(i-j,nums) + abs(nums[i]-nums[i-j]);
			ans= min(ans,jmp);
		}
	}
	return dp[i]=ans;
}	

signed main()
{	
	int n;
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	vector<int>nums(n);
	for (int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<func(n-1,nums);
	
	
	return 0;
}