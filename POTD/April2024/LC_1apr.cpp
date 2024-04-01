//Length of Last Word (Easy)
// Given a string s consisting of words and spaces, return the length of the last word in the string.

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;
        int last = 0;
        for (int i=0;i<n;i++){
            if (s[i]==' '){
                if (cnt!=0){
                    last = cnt;
                }
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
        if (cnt!=0){
            last = cnt;
        }
       
        return last;
    }
};
signed main()
{    
    string s;
    getline(cin,s);
    Solution ob;
    auto ans = ob.lengthOfLastWord(s);
    cout<<ans;
    return 0;
}