// Sum of Digits of String After Convert (Easy)

// You are given a string s consisting of lowercase English letters, and an integer k.
// First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.
// For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:
// Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
// Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
// Transform #2: 17 ➝ 1 + 7 ➝ 8
// Return the resulting integer after performing the operations described above.

// Input: s = "iiii", k = 1
// Output: 36
// Explanation: The operations are as follows:
// - Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
// - Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
// Thus the resulting integer is 36.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.length();
        string t;
        for(int i=0;i<n;i++){
            t+=to_string(s[i]-'a'+1);
        }
        int ans;
        string temp = t;
        for(int i=0;i<k;i++){
            ans = 0;
            for(int j=0;j<temp.length();j++){
                ans+=(temp[j]-'0');
            }
            temp = to_string(ans);
        }
        return ans;
    }
};

signed main()
{  
    string s;
    cin>>s;
    int k;
    cin>>k;
    Solution ob;
    auto ans = ob.getLucky(s,k);
    cout<<ans;
    return 0;
}