#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(map<char,int>&mps,map<char,int>&mpt){
        for (char i = 'a';i<='z';i++){
            if (mpt[i]!=0 && mpt[i] > mps[i]){
                return false;
            }
        }
        for(char i='A';i<='Z';i++){
            if (mpt[i]!=0 && mpt[i] > mps[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length();
        map<char,int>mps;
        map<char,int>mpt;
        int l = 0;
        int r = 0;
        int cnt = INT_MAX;
        string ans;
        for (auto c:t){
            mpt[c]++;
        }
        while(r<n){
            mps[s[r]]++;
            while(l<=r && (mpt[s[l]]==0 || mps[s[l]] > mpt[s[l]])){
                mps[s[l]]--;
                l++;
            }
            if (check(mps,mpt)){
                if (cnt>r-l+1){
                    cnt = r-l+1;
                    ans = s.substr(l,cnt);
                }
                mps[s[l]]--;
                l++;
            }
            r++;
        }

        return ans;
    }
};
signed main()
{    
    string s,t;
    cin>>s>>t;
    Solution ob;
    auto ans = ob.minWindow(s,t);
    cout<<ans;
    return 0;
}