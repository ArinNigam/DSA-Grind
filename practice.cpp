// 11:55 - cutoff
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>ans;
        map<int,int>mp;
        int maxi = 0;
        for (int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi = max(maxi,mp[nums[i]]);
        }
        // for (auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for (int i=0;i<maxi;i++){
            vector<int> temp;
            for (int j=0;j<n;j++){
                if (find(temp.begin(),temp.end(),nums[j])==temp.end() && mp[nums[j]]!=0){
                    temp.push_back(nums[j]);
                    mp[nums[j]]--;
                }
                // cout<<mp[nums[j]]<<" ";
            }
            ans.push_back(temp);
            // cout<<endl;
        }
        return ans;
        
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
    auto ans = ob.findMatrix(nums);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}