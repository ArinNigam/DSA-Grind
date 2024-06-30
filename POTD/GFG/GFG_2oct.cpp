#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    const int mod = 1e9+7;
    int func(int ind,string s,string &t,unordered_set<string>&st,int n,vector<int>&dp){
        if (ind==n){
            if (st.find(s)==st.end()){
                st.insert(s);
                return 1;
            }
            return 0;
        }
        s += t[ind];
        int pick = func(ind+1,s,t,st,n,dp);
        s.pop_back();
        
        int notPick = func(ind+1,s,t,st,n,dp);
        return dp[ind]= pick%mod+notPick%mod;
    }
    int distinctSubsequences(string s)
    {
        // Your code goes here
        int n = s.size();
        vector<long long>dp(n+1,0);
        unordered_map<char,int>mp;
        dp[0] = 1;
        for (int i=1;i<=n;i++){
            dp[i] = (dp[i-1]*2)%mod;
            if (mp.find(s[i-1])!=mp.end()){
                int j= mp[s[i-1]];
                dp[i] = dp[i]%mod - dp[j-1]%mod;
                
            }
            dp[i] = (dp[i]+mod)%mod;
            mp[s[i-1]] = i;
        }
        return dp[n];
        
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.distinctSubsequences(s);
    cout<<ans;
    return 0;
}