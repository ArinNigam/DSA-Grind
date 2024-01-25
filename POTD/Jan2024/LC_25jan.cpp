// Longest Common Subsequence (Medium)
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for (int i =1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if (s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

signed main()
{    
    string s1,s2;
    cin>>s1>>s2;
    Solution ob;
    auto ans = ob.longestCommonSubsequence(s1,s2);
    cout<<ans;
    return 0;
}