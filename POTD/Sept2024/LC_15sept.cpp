//  Find the Longest Substring Containing Vowels in Even Counts (Medium)
// Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int>mp{{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
        int mask = 0;
        int maxi = 0;
        unordered_map<int,int>mpp;
        mpp[0] = -1;
        for(int i=0;i<n;i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                mask ^= (1 << mp[s[i]]);
            }

            if (mpp.find(mask)!=mpp.end()){
                maxi = max(maxi,i - mpp[mask]);
            }
            else{
                mpp[mask] = i;
            }
        }
        return maxi;
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.findTheLongestSubstring(s);
    cout<<ans;
    return 0;
}