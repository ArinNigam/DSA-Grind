// Longest Palindromic Substring
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        // toh is ques me hame substring niklna h jo
        // palindrome h aur sabse lamba h
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        // All substrings of length 1
        // base case 1
        for (int i=0;i<n;i++){
            dp[i][i] = true;
        }
        // all strings of len = 1 are palindrome 
        // hence maxi = 1
        int maxi = 1;
        int startInd = 0;
        
        // compare karo cur aur next character ko
        // base case 2
    
        for (int i=0;i<n-1;i++){
            if (s[i]==s[i+1]){
                dp[i][i+1] = true;
                startInd = i;
                maxi = 2;
            }
        }
        
        // compare karo curr aur 3-n character ko
        for (int len=3;len<=n;len++){
          for (int i=0;i<n-len+1;i++){
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i+1][j-1] ){
                dp[i][j] = true;
                if (len>maxi){
                    startInd = i;
                    maxi = len;
                }
            }
          }
        }
        return s.substr(startInd,maxi);

    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.longestPalindrome(s);
    cout<<ans;
    return 0;
}