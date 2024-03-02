///Maximum Odd Binary Number (Easy)

// You are given a binary string s that contains at least one '1'.
// You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
// Return a string representing the maximum odd binary number that can be created from the given combination.
// Note that the resulting string can have leading zeros.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt0 = count(s.begin(),s.end(),'0');
        int cnt1 = count(s.begin(),s.end(),'1');
        string t ="";
        for (int i=0;i<cnt1-1;i++){
            t+='1';
        }
        for (int i=0;i<cnt0;i++){
            t+='0';
        }
        t+='1';
        return t;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.solve(nums);
    cout<<ans;
    return 0;
}