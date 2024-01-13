// Determine if String Halves Are Alike (Easy)
// Two strings are alike if they have the same number of vowels 
// Input: s = "book"
// Output: true
// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int cnt1 =0;
        int cnt2 =0;
        unordered_set<char>st {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i=0;i<n/2;i++){
            if (st.find(s[i])!=st.end()){
                cnt1++;
            }
        }
        for (int i=n/2;i<n;i++){
            if (st.find(s[i])!=st.end()){
                cnt2++;
            }
        }
        return cnt1==cnt2;
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.halvesAreAlike(s);
    cout<<((ans==1) ? "true" : "false");
    return 0;
}