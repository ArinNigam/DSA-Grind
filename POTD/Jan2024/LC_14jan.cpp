// Determine if Two Strings Are Close (Medium)

// Two strings are considered close if you can attain one from the other using the following operations:

// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb

// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// Example 1:

// Input: word1 = "cabbba", word2 = "abbccc"
// Output: true
// Explanation: You can attain word2 from word1 in 3 operations.
// Apply Operation 1: "cabbba" -> "caabbb"
// Apply Operation 2: "caabbb" -> "baaccc"
// Apply Operation 2: "baaccc" -> "abbccc"

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size()!=word2.size()){
            return false;
        }
        map<char,int>mp1,mp2;
        for (int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
        }
        for (int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
        }
        
        for (auto i:mp1){
            bool flag = 0;
            if (mp2.find(i.first)==mp2.end()){
                return false;
            }
        }
        for (auto i:mp1){
            bool flag = 0;
            for (auto j:mp2){
                if (i.second==j.second){
                    mp2.erase(j.first);
                   
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0){
                return false;
            }
        }
        return true;
    }
};

signed main()
{    
    string s,t;
    cin>>s>>t;
    
    Solution ob;
    auto ans = ob.closeStrings(s,t);
    cout<<ans;
    return 0;
}