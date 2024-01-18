// Unique Number of Occurrences
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for (int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        unordered_set<int>st;
        for (auto it:mp){
            if (st.find(it.second)==st.end()){
                st.insert(it.second);
            }
            else{
                return false;
            }
        }
        return true;
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
    auto ans = ob.uniqueOccurrences(nums);
    cout<<ans;
    return 0;
}x