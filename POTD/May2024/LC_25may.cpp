// Word Break II
// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string>ans;
    void solve(int ind,string s,unordered_set<string>&st,string temp){
        if (ind>=s.length()){
            ans.push_back(temp);
            return;
        }
        for (int i=ind;i<s.length();i++){
            string x = s.substr(ind,i-ind+1);
            if (st.find(x)!=st.end()){
                if (temp.empty()){
                    solve(i+1,s,st,x);
                }
                else{
                    solve(i+1,s,st,temp+" "+x);
                }      
            }
            
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        solve(0,s,st,"");
        return ans;
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
    for (auto it:ans){
        cout<<it<<endl;
    }
    return 0;
}