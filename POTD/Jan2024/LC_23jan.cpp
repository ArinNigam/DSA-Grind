// Maximum Length of a Concatenated String with Unique Characters (Medium)

// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
// Return the maximum possible length of s.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind,vector<string>&ans,vector<string>&arr,unordered_map<string,int>&dp){
        if (ind >= arr.size()) return 0;
        string curr = "";
        for (auto it:ans){
            curr+=it;
        }
        if (dp.find(curr)!=dp.end()){
            return dp[curr];
        }
        ans.push_back(arr[ind]);
        unordered_map<char,int> mp;
        for (int i=0;i<ans.size();i++){
            for (int j=0;j<ans[i].size();j++){
                mp[ans[i][j]]++;
            }
        }
        bool flag = 1;
        for (auto it:mp){
            if (it.second > 1){
                flag =0;
                break;
            }
        }
        
        int pick = 0;
        int notPick = 0;
        if (flag ==1){
            pick = arr[ind].size() + solve(ind+1,ans,arr,dp);
        }
        ans.pop_back();
        
        notPick = solve(ind+1,ans,arr,dp);
        
        return dp[curr] = max(pick,notPick);
        
    }
    int maxLength(vector<string>& arr) {
        unordered_map<string,int>dp;
        vector<string>ans;
        return solve(0,ans,arr,dp);
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<string>arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution ob;
    auto ans = ob.maxLength(arr);
    cout<<ans;
    return 0;
}