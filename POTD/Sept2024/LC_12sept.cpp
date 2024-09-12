// Count the Number of Consistent Strings (Easy)

// You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
// Return the number of consistent strings in the array words.
// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
// Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        for(auto word:words){
            for(auto i:word){
                if (allowed.find(i) == string::npos){
                    cnt--;
                    break;
                }
            }
            cnt++;
        }
        return cnt;
    }
};

signed main()
{    
    string s;
    int n;
    cin>>n;
    vector<string>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.countConsistentStrings(s,nums);
    cout<<ans;
    return 0;
}