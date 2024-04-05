//Maximum Nesting Depth of the Parentheses (Easy)

// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation: Digit 8 is inside of 3 nested parentheses in the string.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char>st;
        int ans = 0;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                st.push('(');
                ans = max(ans,(int)st.size());
            }
            else if(s[i]==')'){
                if (!st.empty()){
                    st.pop();
                }
                
            }
        }
        return ans;
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.maxDepth(s);
    cout<<ans;
    return 0;
}