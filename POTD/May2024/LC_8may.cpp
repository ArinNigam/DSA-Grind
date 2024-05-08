// Relative Ranks (Easy)

// The 1st place athlete's rank is "Gold Medal".
// The 2nd place athlete's rank is "Silver Medal".
// The 3rd place athlete's rank is "Bronze Medal".
// For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
// Return an array answer of size n where answer[i] is the rank of the ith athlete.

// Example 1:

// Input: score = [5,4,3,2,1]
// Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
// Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        vector<pair<int,int>>vp(n);
        
        for (int i=0;i<n;i++){
            vp[i] = make_pair(score[i],i);
        }
        sort(vp.rbegin(),vp.rend());
        vector<string> ans(n);
        for (int i=0;i<n;i++){
            switch(i){
                case 0:
                    ans[vp[i].second] = "Gold Medal";
                    break;
                case 1:
                    ans[vp[i].second] = "Silver Medal";
                    break;
                
                case 2:
                    ans[vp[i].second] = "Bronze Medal";
                    break;
                default:
                    ans[vp[i].second] = to_string(i+1);
            }
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
    auto ans = ob.findRelativeRanks(nums);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}