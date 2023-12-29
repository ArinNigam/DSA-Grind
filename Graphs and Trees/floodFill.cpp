// Flood Fill 
// Fill with newColor
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];
int m,n;
void dfs(int i,int j,vector<vector<int>>&nums,int prev_color,int color){
  int m = nums.size();
  int n = nums[0].size();
  if (i<0 || j<0 ) return;
  if (i>=m || j>=n) return;
  if (nums[i][j]!= prev_color) return;
  
  nums[i][j]=color;
  
  dfs(i-1,j,nums,prev_color,color);
  dfs(i,j-1,nums,prev_color,color);
  dfs(i+1,j,nums,prev_color,color);
  dfs(i,j+1,nums,prev_color,color);
}  
signed main()
{  
  cin>>m>>n;
  vector<vector<int>>nums(m,vector<int>(n));
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      cin>>nums[i][j];
    }
  }
  int sr,sc;
  cin>>sr>>sc;
  int color;
  cin>>color;
  int prev_color=nums[sr][sc];
  dfs(sr,sc,nums,prev_color,color);
  
  for (auto i: nums){
    for (auto j: i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}