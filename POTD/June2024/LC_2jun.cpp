// Reverse String (Easy)

// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.
// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size()-1;
        while(l<=r){
            swap(s[l++],s[r++]);
        }
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<char>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    ob.reverseString(nums);
    for (auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}