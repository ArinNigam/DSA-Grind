// Group Anagrams
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// TC - O(n*k*logk)
// k -> str[i].size()

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans; 
        unordered_map<string,int>mp;
        
        for (int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if (mp.find(temp)!=mp.end()){
                ans[mp[temp]].push_back(strs[i]);
            }
            else{
                mp[temp] = ans.size();
                ans.push_back({strs[i]});
            }
        }
        return ans;
       
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<string>strs(n);
    for (int i=0;i<n;i++){
        cin>>strs[i];
    }
    Solution ob;
    auto ans = ob.groupAnagrams(strs);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}