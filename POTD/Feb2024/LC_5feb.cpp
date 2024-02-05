// First Unique Character in a String
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        for (int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for (int i=0;i<s.length();i++){
            if (mp[s[i]]==1){
                return i;
            }
        }
        return -1;  
    }
};

signed main()
{    
    string s;
    Solution ob;
    auto ans = ob.firstUniqChar(s);
    cout<<ans;
    return 0;
}