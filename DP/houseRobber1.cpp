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
int func(int i,vector<int>& nums,int dp[]){
	if(i<0){
		return 0;
	}
	if (dp[i]!=-1){
		return dp[i];
	}
	// jahn par bhi sum karna pade wahn par nums[ind] use kar
	int pick = nums[i] + func(i-2,nums,dp); // le rha hu toh agla nhi le skta
	int notpick= 0 + func(i-1,nums,dp); // nahi le raha, agla wala lunga
	return dp[i]=max(pick,notpick); // max karde bhai 
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
	cout<<func(n-1,nums,dp)<<endl;
	
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
	cout<<dp[n-1]<<endl;

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