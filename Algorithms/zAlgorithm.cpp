#include<bits/stdc++.h>
using namespace std;

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
signed main()
{    
    string text;
    string pattern;
    cin>>text>>pattern;
    string s;
    for (char c: pattern){
        s+=c;
    }
    s+='$';
    for (char c: text){
        s+=c;
    }
    
    auto Z = calculateZ(s);
    vector<int>ans;
    for (int i=0;i<Z.size();i++){
        if (Z[i]==pattern.length()){
            ans.push_back(i-pattern.length()-1);
        }
    }
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<(int)( (ans.size()==0) ? -1 : ans[0]);
    
    
    return 0;
}