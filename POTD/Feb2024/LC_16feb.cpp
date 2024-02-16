// Least Number of Unique Integers after K Removals (Medium)

// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second < p2.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<pair<int,int>>vp;
        map<int,int>mp;
        int n= arr.size();
        for (int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for (auto it:mp){
            vp.push_back({it.first,it.second});
        }
        sort(vp.begin(),vp.end(),cmp);
        int cnt = 0;
        for (int i=0;i<vp.size();i++){
            if (k>=vp[i].second){
                cnt++;
                k-=vp[i].second;
                mp.erase(vp[i].first);
            }
            else{
                break;
            } 
        }
        
        return mp.size();
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.findLeastNumOfUniqueInts(nums,k);
    cout<<ans;
    return 0;
}