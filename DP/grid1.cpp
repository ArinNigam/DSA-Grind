// n days m tasks problems 
// Maximise the number of points

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

int func(int i, int j,vector<vector<int>>& nums){
  int m = nums[0].size();
  if (i==0){
    if (j==0 || j==m-1){
      return nums[i][j];
    }
    else{
      return 0;
    }
    
  }
  if (j<0 || j>= m){
    return 0;
  }
  int left = nums[i][j];
  if (j-1>=0) left+= func(i-1,j-1,nums);
  
  int st = nums[i][j] + func(i-1,j,nums);
  
  int right = nums[i][j];
  if (j+1<m) right+= func(i-1,j+1,nums);
  
  return max({left,st,right});
  
}  
signed main()
{  
  int n,m;
  cin>>n>>m;
  vector<vector<int>>nums(n,vector<int>(m));
  vector<vector<bool>>vis(n,vector<bool>(m));
  for (int i=0;i<n;i++){
    for (int j = 0 ;j<m;j++){
      cin>>nums[i][j];
    }
  }
  
  int ans = 0;
  for (int i=0;i<m;i++){
    ans = max(ans,func(n-1,i,nums));
  }
  cout<<ans<<endl;
  return 0;
}