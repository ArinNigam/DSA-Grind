// Decode Ways ( Medium)
// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"

// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)


// Input: s = "12"
// Output: 2
// Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

// Input: s = "226"
// Output: 3
// Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s,int ind,vector<int>&dp){
        if (ind==s.length()){
            return 1;
        }
        if (s[ind]=='0'){
            return 0;
        }
        if (dp[ind]!=-1){
            return dp[ind];
        }
        int ways = solve(s,ind+1,dp);
        
        if (ind + 1 < s.length() && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6'))){
            ways += solve(s,ind+2,dp);
        }
        return dp[ind] = ways;
    }
    int numDecodings(string s){
        int len = s.length();
        vector<int>dp(len,-1);
        return solve(s,0,dp);
    }
};
signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.numDecodings(s);
    cout<<ans;
    return 0;
}