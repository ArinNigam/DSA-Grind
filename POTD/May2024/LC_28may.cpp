// Get Equal Substrings Within Budget (Medium)
// You are given two strings s and t of the same length and an integer maxCost.
// You are given two strings s and t of the same length and an integer maxCost.

// You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

// Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

// Example 1:

// Input: s = "abcd", t = "bcdf", maxCost = 3
// Output: 3
// Explanation: "abc" of s can change to "bcd".
// That costs 3, so the maximum length is 3.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int i=0,j=0;
        int cst = maxCost;
        int maxi = 0;
        while(j<n){
            if (cst - abs(s[j]-t[j])< 0){
                maxi = max(maxi,j-i);
                cst += abs(s[i]-t[i]);
                i++;
            }
            else{
                cst -= abs(s[j]-t[j]);
                j++;
            }
        }
        maxi = max(maxi,j-i);
        return maxi;
    }
};

signed main()
{    
    string s,t;
    cin>>s>>t;
    int maxCost;
    cin>>maxCost;
    Solution ob;
    auto ans = ob.equalSubstring(s,t,maxCost);
    cout<<ans;
    return 0;
}