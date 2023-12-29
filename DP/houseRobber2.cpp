// Mr X robbery 
// Condition: Points can't be Adjacent
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;

int dp[N];

int rob(vector<int>& nums){
  int n =nums.size();
  int ans1=0,ans2=0;
  if (n==1){
    return nums[0];
  }
  // Either First or Last 
  
  // First
  
  int prev = nums[0];
  int prev2=0;
  for (int i=1;i<n-1;i++){ 
    int pick = nums[i]+prev2;
    int notPick = 0 + prev;
    ans1 = max(pick,notPick);
    prev2 = prev;
    prev = ans1;
  }
  ans1 = prev;
  // Last
  prev = nums[1];
  prev2 = 0;
  for (int i=2;i<n;i++){
    int pick = nums[i]+prev2;
    int notPick = 0 + prev;
    ans2 = max(pick,notPick);
    prev2 = prev;
    prev = ans2;
  }
  ans2 = prev;
  return max(ans1,ans2);
}  

int func(int i,vector<int>&nums){
	if(i<0){
		return 0;
	}
	
	int pick =nums[i] + func(i-2,nums);
	
	int notPick = 0 + func(i-1,nums);
	
	return max(pick,notPick);
}	
void solve()
{	
	int n;
	cin>>n;
	vector<int>nums(n);
	for (int i=0;i<n;i++){
		cin>>nums[i];
	}
	if (n==1){
		cout<<nums[0];
	}
	else{
		cout<<max(func(n-2,nums),func(n-1,nums)-nums[0]);
	}
	
	
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		solve();
		cout<<endl;
	}
}
