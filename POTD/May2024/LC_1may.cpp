// Reverse Prefix of Word (Easy)

// Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

// For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
// Return the resulting string.

// Input: word = "abcdefd", ch = "d"
// Output: "dcbaefd"
// Explanation: The first occurrence of "d" is at index 3. 
// Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        stack<char>st;
        int i;
        for (i=0;i<n;i++){
            if (word[i]!=ch){
                st.push(word[i]);
            }
            else{
                st.push(word[i]);
                break;
            }    
        }
        
        string ans;
        if (word.size()==st.size() && st.top()!=ch){
            return word;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        i++;
        for (i;i<n;i++){
            ans+=word[i];
        }
        return ans;
    }
};

signed main()
{    
    string word;
    cin>>word;
    char ch;
    cin>>ch;
    Solution ob;
    auto ans = ob.reversePrefix(word,ch);
    cout<<ans;
    return 0;
}