#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int c = 0;
        map<char,pair<int,int>>mp;
        int ans = -1;
        for (int i=0;i<s.size();i++){
            mp[s[i]].first++;
            if (mp[s[i]].first == 1){
                mp[s[i]].second = i;
            }
            if (mp[s[i]].first>=2){
                ans = max(ans,i-mp[s[i]].second-1);
            }
            
        }
        return ans;
    }
};
signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.maxLengthBetweenEqualCharacters(nums);
    cout<<ans;
    return 0;
}