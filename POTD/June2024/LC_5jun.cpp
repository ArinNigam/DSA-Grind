// Find Common Characters (Easy)

// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

// Example 1:
// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        unordered_map<char,int>mp;
        for (int i=0;i<words.size();i++){
            unordered_map<char,int>mp1;
            if(i==0){
                for (auto j:words[i]){
                    mp[j]++;
                }
                continue;
            }
           
            for (auto j:words[i]){
                mp1[j]++;
            }
            for (auto it:mp1){
                if (mp.find(it.first)==mp.end()){
                    mp.erase(it.first);
                }
                else{
                    mp[it.first] = min(mp[it.first],mp1[it.first]);
                }
            }
            
            for (auto it:mp){
                if (mp1.find(it.first)==mp1.end()){
                    mp[it.first] = 0;
                }
            }
            
        }
        
        for (auto it:mp){
            if (it.second != 0){
                for (int i= 0;i<it.second;i++){
                    ans.push_back(string(1,it.first));
                }
            }   
        }
        
        return ans;
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<string>words(n);
    for (int i=0;i<n;i++){
        cin>>words[i];
    }
    Solution ob;
    auto ans = ob.commonChars(words);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}