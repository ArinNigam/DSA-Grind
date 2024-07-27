// Sort the People (Easy)

// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
// For each index i, names[i] and heights[i] denote the name and height of the ith person.
// Return names sorted in descending order by the people's heights.

// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
// Output: ["Mary","Emma","John"]
// Explanation: Mary is the tallest, followed by Emma and John.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<string,int>&p1,pair<string,int>&p2){
        return p1.second > p2.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> ans;
        vector<pair<string,int>>vp;
        for(int i=0;i<names.size();i++){
            vp.push_back({names[i],heights[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        
        for(int i=0;i<n;i++){
            ans.push_back(vp[i].first);
        }
        return ans;
    }
};

signed main()
{  
  int n;
  cin>>n;
  vector<int>names(n),heights(n);
  for (int i=0;i<n;i++){
    cin>>names[i];
  }
  for (int i=0;i<n;i++){
    cin>>heights[i];
  }
  Solution ob;
  auto ans = ob.sortPeople(names,heights);
  cout<<ans;
  return 0;
}