// Custom Sort String (Medium)
// You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
// Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.
// Input:  order = "cba", s = "abcd" 

// Output:  "cbad" 

// Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

// Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for (auto it:order){
            mp[it]= 0;
        }
        for (auto it:s){
            if (mp.find(it)!=mp.end()){
                mp[it]++;
            }
        }
        string ans;
        
        for (auto it:order){
            ans.append(mp[it],it);
        }
        for (auto it:s){
            if (mp.find(it)==mp.end()){
                ans.push_back(it);
            }
        }
        return ans;
    }
};

signed main()
{   
    string order,s;
    cin>>order>>s;
    Solution ob;
    auto ans = ob.customSortString(order,s);
    cout<<ans;
    return 0;
}