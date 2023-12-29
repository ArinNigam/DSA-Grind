#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,string &s1, string &s2,vector<vector<int>>&dp){
  if (i<0) return 0;
  if (j<0) return 1;
  
  if (s1[i]==s2[j]){
    return dp[i][j] = solve(i-1,j-1,s1,s2,dp) + solve(i-1,j,s1,s2,dp);
  }
  return dp[i][j] = solve(i-1,j,s1,s2,dp);
  
}  
int tabulate(string &s1,string &s2){
  int n = s1.length();
  int m = s2.length();
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  for (int i=0;i<=n;i++){
    dp[i][0]=1;
  }
  
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      if (s1[i-1]==s2[j-1]){
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][m];
}
int optimise(string &s1, string &s2){
  // storing rows values
  int n = s1.length();
  int m = s2.length();
  
  vector<double>prev(m+1,0),curr(m+1,0);
  prev[0] = curr[0] =1;
  
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      if (s1[i-1]==s2[j-1]){
        curr[j] = prev[j-1] + prev[j];
      }
      else{
        curr[j] = prev[j];
      }
    }
    prev = curr;
  }
  return prev[m];
}
int moreoptimise(string &s1, string &s2){
  int n = s1.length();
  int m = s2.length();
  vector<int>prev(m+1,0);
  prev[0] =1;
  for (int i=1;i<=n;i++){
    for (int j=m;j>=0;j--){
      if (s1[i]==s2[j]){
        prev[j] += prev[j-1];
      }
    }
  }
  return prev[m];
}
signed main()
{  
  string s1,s2;
  cin>>s1>>s2;
  int n = s1.length();
  int m = s2.length();
  cout<<tabulate(s1,s2);
  cout<<optimise(s1,s2);
  cout<<moreoptimise(s1,s2);
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  
  return 0;
}