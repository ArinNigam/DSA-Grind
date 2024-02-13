#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string word){
        int l = 0;
        int r = word.size()-1;
        while(l<=r){
            if (word[l++]!=word[r--]){
                return 0;
            }
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            if (isPalindrome(words[i])==1){
                return words[i];
            }
        }
        return "";
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<string>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.firstPalindrome(nums);
    cout<<ans;
    return 0;
}