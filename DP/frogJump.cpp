//Frog Jump1
// Minimum Number of energy frog takes
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
int dp[N];

int func(int i,vector<int>& nums){
	if (i==0){
		return 0;
	}
	int left=INT_MAX;
	int right=INT_MAX;
	if (dp[i]!=-1){
		return dp[i];
	}
	left= func(i-1,nums)+ abs(nums[i]-nums[i-1]);
	if (i>1){
		right=func(i-2,nums)+ abs(nums[i]-nums[i-2]);
	}
	
	return dp[i]=min(left,right);
	
}	
signed main()
{	
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	vector<int>nums(n);
	for (int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<func(n-1,nums);
	
	
	return 0;
}