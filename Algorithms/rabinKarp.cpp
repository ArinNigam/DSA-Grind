// Rabin Karp Algorithm

// TC - O(n+m) Best Case O(nm) Worst Case
// SC - O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int q = INT_MAX;
  vector<int> search(string text,string pat){
      int n = text.size();
      int m = pat.size();
      vector<int> ans;
      
      int d = 256;
      int p = 0;
      int t = 0;
      int h = 1;
      
      for(int i=0;i<m-1;i++){
        h = (h*d) % q;
      }
      for(int i=0;i<m;i++){
        p = (p*d + pat[i]) % q;
        t = (t*d + text[i]) % q;
      }
      for(int i=0;i<=n-m;i++){
        if (p==t){
          for(int j=0;j<m;j++){
              if(text[i+j]!=pat[j]){
                break;
              }
          }
          ans.push_back(i);
        }
        
        if (i<n-m){
          t = ( (t-text[i]*h) * d + text[i+m]) % q;
          
          if (t<0){
              t+=q;
          }
        }
      }
      return ans;
  }
};

signed main()
{  
  
  string s,t;
  cin>>s>>t;
  Solution ob;
  auto ans = ob.search(s,t);
  for(auto it:ans){
    cout<<it<<" ";
  }
  return 0;
}