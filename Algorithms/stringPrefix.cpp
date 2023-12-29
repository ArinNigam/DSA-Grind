// Input: abcba

// Output: 
// 3 1 0
// 3 0 0
// 2 0 0
// 1 0 0
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
    string s;
    cin>>s;
    auto Z = calculateZ(s);
    int n = s.length();
    // for (auto i:Z){
    //     cout<<i<<" ";
    // }
    vector<int> big(s.length()+1,0), equal(s.length()+1,0), small(s.length()+1,0);
    
    for (int i=1;i<s.size();i++){
        if (Z[i]==0){
            if (s[i]>s[0]){
                big[0]++;
                big[n-i]--;
            }
            else{
                small[0]++;
                small[n-i]--;
            }
        }
        else{
            equal[0]++;
            equal[Z[i]]--;
            if (n-i == Z[i]) continue;
            if (s[i+Z[i]]> s[Z[i]]){
                big[Z[i]]++;
                big[n-i]--;
            }
            else{
                small[Z[i]];
                small[n-i]--;
            }
        }
    }
    
    for (int i=1;i<n;i++){
        big[i]+=big[i-1];
        equal[i]+=equal[i-1];
        small[i]+=small[i-1];
    }
    for (int i=0;i<n-1;i++){
        cout<<big[i]<<" "<<equal[i]<<" "<<small[i]<<endl;
    }
    
    
    
    return 0;
}