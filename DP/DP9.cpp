#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

#define for(j,n) for (int i=j;i<n;i++)

//Linear Vector
#define append push_back
#define pop() pop_back()
#define all(v) v.begin(),v.end()
#define max(v) *max_element(all(v))
#define min(v) *max_element(all(v))
#define sum(v) accumulate(all(v),0)
#define sort(v) sort(all(v))

//Pair Vector
#define ff first
#define ss second

const int N=1e5+5;

int dp[205][20005];
int func(int ind,int sum,vector<int>&nums){
	if (sum==0){
		return 1;
	}
	if (ind < 0){
		return 0;
	}
	if (dp[ind][sum]!=-1){
		return dp[ind][sum];
	}
	if (sum-nums[ind]>=0){
		bool isPossible=func(ind-1,sum,nums) || func(ind-1,sum-nums[ind],nums);
		return dp[ind][sum]=isPossible;
	}
	
}
bool canPartition(vector<int>& nums){
	int sum=accumulate(nums.begin(),nums.end(),0);
	if (sum%2!=0){
		return 0;
	}
	else{
		sum=sum/2;
		return func(nums.size()-1,sum,nums);
	}
    }

signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--){
		int n;
		cin>>n;
		vector<int>v(n);
		for(0,n){
			cin>>v[i];
		}
		cout<<canPartition(v)<<endl;
	}
	return 0;
}
