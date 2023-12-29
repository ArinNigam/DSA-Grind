#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s){
        map<char,int>mp;
        for (int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        unordered_set<int>st;
        int cnt = 0;
        for (auto i:mp){
            int freq= i.second;
            while(st.find(freq)!=st.end() && i.second>=0){
                cnt++;
                freq--;
            }
            st.insert(freq);
        }
        return cnt;
    }
};

signed main()
{    
    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.solve(s);
    cout<<ans;
    return 0;
}