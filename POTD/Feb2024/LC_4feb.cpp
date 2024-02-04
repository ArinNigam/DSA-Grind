// Minimum Window Substring (Hard)
//Given two strings s and t of lengths m and n respectively, return the minimum window substring
// of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// HINT : 2 pointer approach use 2 map to track count of characters 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(map<char,int>&mps,map<char,int>&mpt){
        for (char i = 'a';i<='z';i++){
            if (mpt[i]!=0 && mpt[i] > mps[i]){
                return false;
            }
        }
        for(char i='A';i<='Z';i++){
            if (mpt[i]!=0 && mpt[i] > mps[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length();
        map<char,int>mps;
        map<char,int>mpt;
        int l = 0;
        int r = 0;
        int cnt = INT_MAX;
        string ans;
        for (auto c:t){
            mpt[c]++;
        }
        while(r<n){
            mps[s[r]]++;
            while(l<=r && (mpt[s[l]]==0 || mps[s[l]] > mpt[s[l]])){
                mps[s[l]]--;
                l++;
            }
            if (check(mps,mpt)){
                if (cnt>r-l+1){
                    cnt = r-l+1;
                    ans = s.substr(l,cnt);
                }
                mps[s[l]]--;
                l++;
            }
            r++;
        }

        return ans;
    }
};
signed main()
{    
    string s,t;
    cin>>s>>t;
    Solution ob;
    auto ans = ob.minWindow(s,t);
    cout<<ans;
    return 0;
}