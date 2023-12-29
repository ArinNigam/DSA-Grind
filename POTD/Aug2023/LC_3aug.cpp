// Letter Combinations of a Phone Number ( Medium )

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string s,int i,string prev,vector<string>&ans){
        map<int,string>m{{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        
        if (i==s.size()){
            if (prev.length()!=0){
                ans.push_back(prev);
            }
        }
        else{
            int key = s[i]-'0';
            for (char x : m[key]){
                solve(s,i+1,prev+x,ans);
            }
        }
        return;
    }
    vector<string> letterCombinations(string s) {
        vector<string>ans;
        solve(s,0,"",ans);
        return ans;
    }
};
signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.letterCombinations(s);
    for (auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}