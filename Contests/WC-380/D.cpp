// Find Beautiful Indices in the Given Array II (Hard)
// You are given a 0-indexed string s, a string a, a string b, and an integer k.

// An index i is beautiful if:
    // 0 <= i <= s.length - a.length
    // s[i..(i + a.length - 1)] == a

// There exists an index j such that:
    // 0 <= j <= s.length - b.length
    // s[j..(j + b.length - 1)] == b
    // |j - i| <= k

// 1 <= k <= s.length <= 5 * 105
// 1 <= a.length, b.length <= 5 * 105
// s, a, and b contain only lowercase English letters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateZ(string &s){
    int n = s.size();
    vector<int>Z(n);
    int left = 0;
    int right = 0;
    for (int i=1;i<n;i++){
        if (i>right){
            left = right = i;
            while(right<n && s[right] == s[right-left]){
                right++;
            }
            Z[i] = right - left;
            right--;
        }
        else{
            int k = i-left;
            if (Z[k] < right - i + 1){
                Z[i] = Z[k];
            }
            else{
                left = i;
                while(right<n && s[right]==s[right-left]){
                    right++;
                }
                Z[i] = right - left;
                right--;
            }
        }
    }
    return Z;
}   

    vector<int> beautifulIndices(string s, string a, string b, int k) {
       
        vector<int> a_ind,b_ind;
        int n = s.size();
        
        string t1 = b + '$' + s;
        string t2 = a + '$' + s;
       
        auto v1 = calculateZ(t1);
        auto v2 = calculateZ(t2);
    
        for (int i=0;i<n+b.size()+1;i++){
            if (v1[i] == b.size() ){
                b_ind.push_back(i-b.size()-1);
            }
        }
        for (int i=0;i<n+a.size()+1;i++){
            if (v2[i] == a.size() ){
                a_ind.push_back(i-a.size()-1);
            }
        }
        vector<int>ans;
        for (auto it:a_ind){
            auto x = lower_bound(b_ind.begin(),b_ind.end(),it-k);
            if (x == b_ind.end()) continue;
            if ((*x) > it+k) continue;
            
            if (x!=b_ind.end()){
               ans.push_back(it);
            }
        }
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