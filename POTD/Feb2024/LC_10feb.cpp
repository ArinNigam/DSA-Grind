// Palindromic Substrings ( Medium)

// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int l,int r,string s){
        while(l<r){
            if (s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
    int isPalindromeOptimised(int l,int r,string &s){
        int cnt = 0;
        while(l >= 0 && r < s.length() && s[l--] == s[r++]){
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt= 0;
        int n=s.size();
        
        //O(N^3)
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                cnt+=isPalindrome(i,j,s);
            }
        }
        // return cnt;
        
        // O(N^2)
        int ans = 0;;
        for(int i = 0; i < s.length() ;i++){
           int j = i;
           int oddLength = isPalindromeOptimised(i,j,s);
           int evenLength= isPalindromeOptimised(i,j+1,s);
           ans += (oddLength + evenLength);
        }
        return ans;
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.countSubstrings(s);
    cout<<ans;
    return 0;
}