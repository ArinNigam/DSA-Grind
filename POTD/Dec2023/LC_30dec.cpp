// Redistribute Characters to Make All Strings Equal (Easy)

// Input: words = ["abc","aabc","bc"]
// Output: true
// Explanation: Move the first 'a' in words[1] to the front of words[2],
// to make words[1] = "abc" and words[2] = "abc".
// All the strings are now equal to "abc", so return true.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if(n==1) return 1;

        vector<int> freq(26,0);
        for (auto it: words){
            for (char c: it){
                freq[c-'a']++;
            }
        }
        for (int i=0;i<26;i++){
            if (freq[i]%n!=0){
                return 0;
            }
        }
        return 1;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<string>words(n);
    for (int i=0;i<n;i++){
        cin>>words[i];
    }
    Solution ob;
    auto ans = ob.makeEqual(words);
    cout<<ans;
    return 0;
}