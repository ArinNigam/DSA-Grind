// Longest Ideal Subsequence (Medium)
// You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

// t is a subsequence of the string s.
// The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
// Return the length of the longest ideal string.

// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

// Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

// Input: s = "acfgbd", k = 2
// Output: 4
// Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
// Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int ind,int prev,string &s,int k,vector<vector<int>>&dp) {
        if(ind < 0){
            return 0;
        }
        if(dp[ind][prev] != -1){
            return dp[ind][prev];
        }
        char ch = prev + 'a';
        int take = 0;
        if(prev == 26 or abs(ch-s[ind]) <= k){
            take = 1 + solve(ind-1,s[ind]-'a',s,k,dp);
        }
        int notTake = solve(ind-1,prev,s,k,dp);

        return dp[ind][prev] = max(take,notTake);
    }
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(27,-1));
        return solve(n-1,26,s,k,dp);
    }
};

signed main()
{    
    string s;
    cin>>s;
    int k;
    cin>>k;
    Solution ob;
    auto ans = ob.longestIdealString(s,k);
    cout<<ans;
    return 0;
}