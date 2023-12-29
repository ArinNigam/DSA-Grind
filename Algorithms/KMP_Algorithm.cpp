// abcba
// bc
// Check if pattern is there
#include<bits/stdc++.h>
using namespace std;

// KMP Algo for Longest prefix which is also a suffix
vector<int> longestHappyPrefix(string s){
    vector<int>lps(s.length());
    int i=0,j=1;
    while(j<s.length()){
        if (s[i]==s[j]){
            lps[j]=i+1;
            i++;
            j++;
        }
        else{
            if (i==0){
                j++;
            }
            else{
                i=lps[i-1];
            }
        }
    }
    return lps;
} 

vector<int> LPS(string s){
    int n = s.length();
    vector<int>lps(n,0);
    for (int i=1;i<n;i++){
        int j = lps[i - 1];
        while(j>0 && s[i]!=s[j]){
            j = lps[j-1];
        }
        if (s[i]==s[j]){
            j++;
        }
        lps[i]=j;
        
    }
    return lps;
}
bool KMP(string s1,string s2,vector<int>&lps){
    int i=0,j=0;
    while(i<s1.length() && j<s2.length()){
        if (s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            if (j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        if (j==s2.length()){
            return true;
        }
    }
    return false;
}    
signed main()
{    
    string s1;
    string s2;
    cin>>s1>>s2;

    string s;
    s = s2 + '$' + s1;
    auto lps = longestHappyPrefix(s);
    cout<<KMP(s1,s2,lps)<<endl;
    auto lps1 = LPS(s);
    for (auto i:lps){
        cout<<i<<" ";
    }
    return 0;
}