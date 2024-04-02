//  Isomorphic Strings( Easy)
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Input: s = "egg", t = "add"
// Output: true


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n!=m){
            return false;
        }
        map<char,int>mp1;
        map<char,int>mp2;
        for (int i=0;i<n;i++){
            if (mp1[s[i]]!=mp2[t[i]]){
                return false;
            }
            mp1[s[i]] = i+1;
            mp2[t[i]] = i+1;
        }
        return true;
        
        
    }
};

signed main()
{    
    string s,t;
    cin>>s>>t;
    
    Solution ob;
    auto ans = ob.isIsomorphic(s,t);
    cout<<ans;
    return 0;
}