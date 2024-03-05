// Minimum Length of String After Deleting Similar Ends (Medium)
// Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
// Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
// Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
// The prefix and the suffix should not intersect at any index.
// The characters from the prefix and suffix must be the same.
// Delete both the prefix and the suffix.

// Input: s = "cabaabac"
// Output: 0
// Explanation: An optimal sequence of operations is:
// - Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
// - Take prefix = "a" and suffix = "a" and remove them, s = "baab".
// - Take prefix = "b" and suffix = "b" and remove them, s = "aa".
// - Take prefix = "a" and suffix = "a" and remove them, s = "".


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        while(i<j && s[i]==s[j]){
            char ch = s[i];
            while(i<=j && s[i]==ch){
                i++;
            }
            while(i<=j && s[j]==ch){
                j--;
            }
        }
        return j-i+1;
    }
};
signed main()
{    
    string s;
    cin>>s;
    
    Solution ob;
    auto ans = ob.minimumLength(s);
    cout<<ans;
    return 0;
}