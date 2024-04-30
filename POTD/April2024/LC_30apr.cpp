#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        vector<int>cnt(1024);
        cnt[0] = 1;
        int mask = 0;
        long long ans = 0;
        for (auto it:word){
            int ind = it-'a';
            mask ^= (1<<ind);
            ans+=cnt[mask];
            
            for (int i=0;i<10;i++){
                int x = mask ^ (1<<i);
                ans+=cnt[x];
            }
            cnt[mask]++;
        }
        return ans;
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.wonderfulSubstrings(s);
    cout<<ans;
    return 0;
}
