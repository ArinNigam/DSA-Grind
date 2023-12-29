// Word Break (Medium)

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.
 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
 

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string s,set<string> &st,map<string,bool>&mp){
        int n = s.length();
        if (n==0) return true;
        if (mp.find(s)!=mp.end()){
            return mp[s]; 
        }
        for (int i=0;i<s.length();i++){
            string pre = s.substr(0,i+1);
            string suf = s.substr(i+1);
            
            if (st.find(pre)!=st.end() && (st.find(suf)!=st.end() || 
            solve(suf,st,mp)==true)){
                return mp[s]=true;
            }
        }
        return mp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        map<string,bool>mp;
        return solve(s,st,mp);
        
    }
};
signed main()
{    
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string>wordDict(n);
    for (int i=0;i<n;i++){
        cin>>wordDict[i];
    }
    Solution ob;
    auto ans = ob.wordBreak(s,wordDict);
    cout<<ans;
    return 0;
}