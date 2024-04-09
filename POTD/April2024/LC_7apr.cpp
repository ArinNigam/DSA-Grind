// Valid Parenthesis String (Medium)

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int maxi = 0;
        int mini = 0;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                maxi++;
                mini++;
            }
            else if (s[i]==')'){
                maxi--;
                mini--;
            }
            else if(s[i]=='*'){
                maxi++;
                mini--;
            }
            if (maxi < 0){
                return false;
            }
            mini = max(mini,0);
        }
        return mini == 0;
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.checkValidString(s);
    cout<<ans;
    return 0;
}