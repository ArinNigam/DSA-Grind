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