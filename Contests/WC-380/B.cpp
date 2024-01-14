// Find Beautiful Indices in the Given Array I (Medium)
// You are given a 0-indexed string s, a string a, a string b, and an integer k.

// An index i is beautiful if:
    // 0 <= i <= s.length - a.length
    // s[i..(i + a.length - 1)] == a

// There exists an index j such that:
    // 0 <= j <= s.length - b.length
    // s[j..(j + b.length - 1)] == b
    // |j - i| <= k

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ans;
        vector<int> a_ind,b_ind;
        int n = s.size();
        if (a.size()> s.size() || b.size() > s.size()){
            return {};
        }
        for (int i=0;i<n-b.size()+1;i++){
            if (s.substr(i,b.length())==b ){
                b_ind.push_back(i);
            }
        }
        for (int i=0;i<n-a.size()+1;i++){
            if (s.substr(i,a.length())==a){
                a_ind.push_back(i);
                for(int j= 0;j<b_ind.size();j++){
                    if (abs(b_ind[j]-i)<=k){
                        ans.push_back(i);
                        break;
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
signed main()
{    
    int k;
    string s,a,b;
    cin>>s>>a>>b>>k;
    Solution ob;
    auto ans = ob.beautifulIndices(s,a,b,k);
    for (auto it:ans){
         cout<<it<<" ";
    }
    return 0;
}