// Longest Substring Without Repeating Characters
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<int,int>mp;
        int l = 0;
        int r = 0;
        int len = 0;
        while(r<n){
            if (mp.find(s[r])!=mp.end()){
                l = max(mp[s[r]]+1,l);
            }
            mp[s[r]] = r;
            len = max(len,r-l+1);
            r++;
        }
        return len;
    }
};
signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    int ans = ob.lengthOfLongestSubstring(s);
    cout<<ans;
    return 0;
}