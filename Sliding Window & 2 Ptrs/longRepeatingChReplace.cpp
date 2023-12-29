// Longest Repeating Character Replacement
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        unordered_map<char,int>mp;
        int maxi = 0;
        int ans = 0 ;
        while(r<n){
            mp[s[r]]++;
            maxi = max(maxi,mp[s[r]]);
            while(r-l+1-maxi > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
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
    int ans = ob.characterReplacement(s,k);
    cout<<ans;
    return 0;
}