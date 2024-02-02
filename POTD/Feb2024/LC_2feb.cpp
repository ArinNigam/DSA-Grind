// Sequential Digits (Medium)
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
// Input: low = 100, high = 300
// Output: [123,234]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for (char a = '1';a<='9';a++){
            string s="";
            for (char b=a;b<='9';b++){
                s+=b;
                if (stoi(s)>=low && stoi(s)<=high){
                    ans.push_back(stoi(s));
                }
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
signed main()
{    
    int low,high;
    cin>>low>>high;
    Solution ob;
    auto ans = ob.sequentialDigits(low,high);
    for (auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}