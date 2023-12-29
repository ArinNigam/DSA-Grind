#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int func(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
  if (i<0 || j<0){
    return 0;
  }
  if (s1[i]==s2[j]){
    return dp[i][j] = 1 + func(i-1,j-1,s1,s2,dp);
  }
  if (dp[i][j]!=-1){
    return dp[i][j];
  }
  else{
    return dp[i][j] = max(func(i-1,j,s1,s2,dp),func(i,j-1,s1,s2,dp));
  }
  
}  

int tabulate(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}

int optimise(string s1,string s2){
  int n=s1.size();
  int m=s2.size();
  
  vector<int>curr(m+1,0);
  vector<int>prev(m+1,0);
  for(int ind1=1;ind1<=n;ind1++){
      for(int ind2=1;ind2<=m;ind2++){
          if(s1[ind1-1]==s2[ind2-1])
              curr[ind2] = 1 + prev[ind2-1];
          else
              curr[ind2] = 0 + max(prev[ind2],curr[ind2-1]);
      }
      prev= curr;
  }
  return prev[m];
    
}
signed main()
{  
  string s1,s2;
  cin>>s1>>s2;
  int n = s1.size();
  int m = s2.size();
  vector<vector<int>>dp(n,vector<int>(m,-1));
  cout<<func(s1.length()-1,s2.length()-1,s1,s2,dp);
  cout<<tabulate(s1,s2);
  cout<<optimise(s1,s2);
  cout<<endl;
  
  return 0;
}