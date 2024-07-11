// Reverse Substrings Between Each Pair of Parentheses (Medium)

// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.

// Input: s = "(abcd)"
// Output: "dcba"

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums){
        
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