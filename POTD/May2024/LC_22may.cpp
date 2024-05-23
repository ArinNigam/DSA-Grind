// Palindrome Partitioning (Medium)

// Given a string s, partition s such that every substring of the partition is a palindrome
// Return all possible palindrome partitioning of s.

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s,int left,int right){

        while(left<=right){
            if (s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
       
    }
    void solve(int ind,string s,vector<string>&temp,vector<vector<string>>&ans){
        if (ind == s.length()){
            ans.push_back(temp);
            return;
        }
        
        for (int i=ind;i<s.length();i++){
            if (isPalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,temp,ans);
                temp.pop_back();
            }   
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,temp,ans); 
        return ans;
    }
};

signed main()
{    
    string s;
    cin>>s;
    
    Solution ob;
    auto ans = ob.partition(s);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}