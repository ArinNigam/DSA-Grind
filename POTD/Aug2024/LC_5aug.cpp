// Kth Distinct String in an Array

// A distinct string is a string that is present only once in an array.
// Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

// Note that the strings are considered in the order in which they appear in the array.
// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
// Explanation:
// The only distinct strings in arr are "d" and "a".
// "d" appears 1st, so it is the 1st distinct string.
// "a" appears 2nd, so it is the 2nd distinct string.
// Since k == 2, "a" is returned. 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:arr){
            if (mp[it]==1){
                k--;
                if (k==0){
                    return it;
                }
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
    int k;
    cin>>k;
    Solution ob;
    auto ans = ob.kthDistinct(nums,k);
    cout<<ans;
    return 0;
}