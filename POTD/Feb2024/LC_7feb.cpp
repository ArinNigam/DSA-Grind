// Sort Characters By Frequency ( Medium )

//Given a string s sort it in decreasing order based on the frequency of the characters.
// Input: s = "tree"
// Output: "eert" 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static cmp(pair<int,char>&p1,pair<int,char>&p2){
        return p1.first > p2.first;
    }
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        vector<pair<int,char>>vp;
        string t;
        for (int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for (auto it:mp){
            vp.push_back({it.second,it.first});
        }
        sort(vp.begin(),vp.end(),cmp);
        for (auto it:vp){
            while(it.first--){
                t+=it.second;
            } 
        }
        return t;
    }
};
signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.frequencySort(s);
    cout<<ans;
    return 0;
}