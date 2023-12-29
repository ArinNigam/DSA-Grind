//Longest String Chain
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static cmp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int>mp;
        int ans = 0;
        for (auto it:words){
            int longest = 0;
            for (int i=0;i<it.size();i++){
                string s = it;
                s.erase(i,1);
                longest = max(longest,mp[s]+1);
            }
            mp[it] = longest;
            ans = max(ans,longest);
        }
        return ans;
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.solve(nums);
    cout<<ans;
    return 0;
}