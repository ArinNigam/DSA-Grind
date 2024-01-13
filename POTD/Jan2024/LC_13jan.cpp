// Minimum Number of Steps to Make Two Strings Anagram ( Medium )
// You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

// Return the minimum number of steps to make t an anagram of s.


// Input: s = "bab", t = "aba"
// Output: 1
// Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
         int n = s.size();
         unordered_map<char,int>mp1,mp2;
         for (int i=0;i<n;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
         }
         int cnt = 0;
         for (auto it: mp1){         
            if (mp2.find(it.first)!=mp1.end() ){
                if (it.second > mp2[it.first] ){
                    cnt+= it.second - mp2[it.first];
                }
            }
            else{
                cnt+=it.second;
            }
         }
         return cnt;
         
    }
};
signed main()
{    
    string s,t;
    cin>>s>>t;
    Solution ob;
    auto ans = ob.minSteps(s,t);
    cout<<ans;
    return 0;
}