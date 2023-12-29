// Subset Sum == Target 
// Most Asked Question in interview

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

int func(int i,int sum,vector<int>& nums,vector<vector<int>>&dp){
	if(sum==0)
        return true;
    
    if(i == 0)
        return nums[0] == sum;
    
    if(dp[i][sum]!=-1)
        return dp[i][sum];
        
    bool notTaken = func(i-1,sum,nums,dp);
    
    bool taken = false;
    if(nums[i]<=sum)
        taken = func(i-1,sum-nums[i],nums,dp);
        
    return dp[i][sum]= notTaken||taken;
	
}	
signed main()
{	
	int n,k;
	cin>>n>>k;
	vector<int>nums(n);
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	for (int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<func(n-1,k,nums,dp);
	dp.clear();
	// Tabulate 
	for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(nums[0]<=k)
        dp[0][nums[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(nums[ind]<=target)
                    taken = dp[ind-1][target-nums[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
	cout<<dp[n-1][k];
	
	// Space Optimise it
	// TC - O(N*K) SC - O()
	vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(nums[0]<=k)
        prev[nums[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(nums[ind]<=target)
                    taken = prev[target-nums[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    cout<<prev[k];
	return 0;
}