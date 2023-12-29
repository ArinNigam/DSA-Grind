// Maximum subsequence sum 
// condition: points can't be adjacent

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];
int dp[N];

//Brute Force Recursion
int func(int i,vector<int>& nums){
	if(i<0){
		return 0;
	}
	if (dp[i]!=-1){
		return dp[i];
	}
	int pick = nums[i] + func(i-2,nums);
	int notpick= 0 + func(i-1,nums);
	return dp[i]=max(pick,notpick);
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
	//Tabluate
	dp[0]=0;
	
	for (int i=1;i<n;i++){
		int take = nums[i];
		if (i>1){
			take+=dp[i-2];
		}
		int nontake= dp[i-1];
		
		dp[i]=max(take,nontake);
	}
	cout<<dp[n-1];
	cout<<endl;
	cout<<func(n-1,nums);
	cout<<endl;
	
	// Space optimization 
	
	int prev=nums[0];
	int prev2=0;
	for(int i=1;i<n;i++){
		int take = nums[i];
		if (i>1){
			take+= prev2;
		}
		int nottake = prev;
		int curi=max(take,nottake);
		prev2=prev;
		prev=curi;
	}
	cout<<prev;
	return 0;
}