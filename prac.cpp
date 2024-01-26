#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int dp[101][20001];
int func1(int i,int sum,int v[])
{
    if(i<0)
    {
      if(sum==0) return 0;
        else return 1e8;
    }
    if(sum==0) return 0;
    // cout<<"hey";
    if(dp[i][sum]!=-1) return dp[i][sum];
    int minn=1e8;
    minn=min(func1(i-1,sum-v[i],v)+1,func1(i-1,sum,v));
    return dp[i][sum]=minn;
}
int func(int i,int sum,int v[])
{
    if(i<0)
    {
        if(sum<0) return 1e8;
        if(sum>=0) return sum;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int minn=1e8;
    minn=min(minn,func(i-1,sum,v));
    if(sum>=v[i])
    minn=min(minn,func(i-1,sum-v[i],v));
    return dp[i][sum]=minn;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    while(t>0)
    {
        t--;
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        int v[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {cin>>v[i];
        sum=sum+v[i];}
        int k= func(n-1,sum/2,v);
        // cout<<k<<"\n"<<"hi"<<"\n";
        memset(dp,-1,sizeof(dp));
        cout<< func1(n-1,sum/2-k,v)<<"\n";
    }
    return 0;
}