// 0/1 Knapsack
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

int func(int ind,int w,vector<int>&weight,vector<int>&nums){
  if (ind==0){
    if (w-weight[0]>=0){
      return nums[0];
    }
    return 0;
  }
  int take = INT_MIN;
  if (w>=weight[ind]){
    take = nums[ind] + func(ind-1,w-weight[ind],weight,nums);
  }
  int notTake = 0 + func(ind-1,w,weight,nums);
  
  return max(take,notTake);
}  
signed main()
{  
  int w,n;
  cin>>w>>n;
  vector<int>weight(n);
  vector<int>val(n);
  for (int i=0;i<n;i++){
    cin>>weight[i];
  }
  for (int i=0;i<n;i++){
    cin>>val[i];
  }
  cout<<func(n-1,w,weight,val);
  return 0;
}